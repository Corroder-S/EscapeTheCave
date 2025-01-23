#include "jeu.h"

Jeu::Jeu() {
	if (!coeur.loadFromFile("assets/coeur.png"))
		return;
	coeur1.setTexture(coeur);
	coeur2.setTexture(coeur);
	coeur3.setTexture(coeur);
	coeur1.setPosition(50, 50);
	coeur2.setPosition(100, 50);
	coeur3.setPosition(150, 50);
}


void Jeu::generate(int room) {
	if (room == 1) {
		ennemis.push_back(new ChaserEnemy(1, 500, 500));
		ennemis.push_back(new PatrollingEnemy(100, 300, 100, 500, 2, 100, 300));
		ennemis.push_back(new PatrollingEnemy(100, 500, 500, 500, 2, 100, 500));
		items.push_back(new Potion((rand()%450)+100, (rand()%750)+100));
		items.push_back(new Key((rand() % 450) + 100, (rand() % 750) + 100));
	}
}

void Jeu::collide(Player* player, sf::RenderWindow& window) {
	int hitDelayint = hitDelay.getElapsedTime().asSeconds();

	for (int i = 0; i < ennemis.size(); i++) {
		if (player->getSprite()->getGlobalBounds().intersects(ennemis[i]->getSprite()->getGlobalBounds()) && hitDelayint > 1) {
			player->setVie(player->getVie() - 1);
			hitDelay.restart();
		}
	}

	for (int i = 0; i < map.walls.size(); i++) {
		if (player->getSprite()->getGlobalBounds().intersects(map.walls[i]->wall_rect.getGlobalBounds())) {
			sf::FloatRect wallBounds = map.walls[i]->wall_rect.getGlobalBounds();
			sf::FloatRect playerBounds = player->getSprite()->getGlobalBounds();

			if (playerBounds.left < wallBounds.left && playerBounds.left + playerBounds.width > wallBounds.left) {
				player->setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
			}
			else if (playerBounds.left > wallBounds.left && playerBounds.left < wallBounds.left + wallBounds.width) {
				player->setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
			}
			if (playerBounds.top < wallBounds.top && playerBounds.top + playerBounds.height > wallBounds.top) {
				player->setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
			}
			else if (playerBounds.top > wallBounds.top && playerBounds.top < wallBounds.top + wallBounds.height) {
				player->setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
			}
		}
	}
	for (int i = 0; i < map.doors.size(); i++) {
		if (player->getSprite()->getGlobalBounds().intersects(map.doors[i]->door_rect.getGlobalBounds())) {
			if (player->getKeyCount() == 0 && !map.doors[i]->open) {
				sf::FloatRect doorBounds = map.doors[i]->door_rect.getGlobalBounds();
				sf::FloatRect playerBounds = player->getSprite()->getGlobalBounds();

				if (playerBounds.left < doorBounds.left && playerBounds.left + playerBounds.width > doorBounds.left) {
					player->setPosition(doorBounds.left - playerBounds.width, playerBounds.top);
				}
				else if (playerBounds.left > doorBounds.left && playerBounds.left < doorBounds.left + doorBounds.width) {
					player->setPosition(doorBounds.left + doorBounds.width, playerBounds.top);
				}
				if (playerBounds.top < doorBounds.top && playerBounds.top + playerBounds.height > doorBounds.top) {
					player->setPosition(playerBounds.left, doorBounds.top - playerBounds.height);
				}
				else if (playerBounds.top > doorBounds.top && playerBounds.top < doorBounds.top + doorBounds.height) {
					player->setPosition(playerBounds.left, doorBounds.top + doorBounds.height);
				}
			}
			else if (player->getKeyCount() > 0) {
				player->setKeyCount(player->getKeyCount() - 1);
				map.doors[i]->open = true;
			}
		}

		for (int i = 0; i < ennemis.size(); i++) {
			for (int j = 0; j < map.walls.size(); j++) {
				if (ennemis[i]->getSprite()->getGlobalBounds().intersects(map.walls[j]->wall_rect.getGlobalBounds())) {
					sf::FloatRect wallBounds = map.walls[j]->wall_rect.getGlobalBounds();
					sf::FloatRect enemyBounds = ennemis[i]->getSprite()->getGlobalBounds();

					if (enemyBounds.left < wallBounds.left && enemyBounds.left + enemyBounds.width > wallBounds.left) {
						ennemis[i]->setPosition(Vector2f(wallBounds.left - enemyBounds.width, enemyBounds.top));
					}
					else if (enemyBounds.left > wallBounds.left && enemyBounds.left < wallBounds.left + wallBounds.width) {
						ennemis[i]->setPosition(Vector2f(wallBounds.left + wallBounds.width, enemyBounds.top));
					}
					if (enemyBounds.top < wallBounds.top && enemyBounds.top + enemyBounds.height > wallBounds.top) {
						ennemis[i]->setPosition(Vector2f(enemyBounds.left, wallBounds.top - enemyBounds.height));
					}
					else if (enemyBounds.top > wallBounds.top && enemyBounds.top < wallBounds.top + wallBounds.height) {
						ennemis[i]->setPosition(Vector2f(enemyBounds.left, wallBounds.top + wallBounds.height));
					}
				}
			}
		}

		for (auto it = items.begin(); it != items.end();) {
			if (player->getSprite()->getGlobalBounds().intersects((*it)->getSprite()->getGlobalBounds())) {
				(*it)->interact(*player);
				if ((*it)->getType() == 1) {
					speedupDelay.restart();
				}

				delete* it;
				it = items.erase(it);
			}
			else {
				++it;
			}
		}
	}
}



	void Jeu::manage(Player * player, RenderWindow & window) {
		int speedupDelay_int = speedupDelay.getElapsedTime().asSeconds();
		if (player->getSpeedUp() && speedupDelay_int > 2) {
			player->setVitesse((player->getVitesse() / 1.5) + 1);
			player->setSpeedUp(false);
		}

		for (int i = 0; i < map.walls.size(); i++) {
			window.draw(map.walls[i]->wall_rect);
		}
		for (int i = 0; i < map.floors.size(); i++) {
			window.draw(map.floors[i]->floor_rect);
		}
		for (int i = 0; i < map.doors.size(); i++) {
			if (map.doors[i]->open) {
				map.doors[i]->door_t.loadFromFile("assets/door_open.png");
				map.doors[i]->door_rect.setTexture(&map.doors[i]->door_t);
			}
			window.draw(map.doors[i]->door_rect);
		}

		for (int i = 0; i < items.size(); i++) {
			items[i]->update(0);
			items[i]->draw(window);
		}

		for (int i = 0; i < ennemis.size(); i++) {

			if (ennemis[i]->getType() == 1) {
				ennemis[i]->move_Enemy(player->getX(), player->getY());
			}
			else if (ennemis[i]->getType() == 2) {
				ennemis[i]->move_Enemy();
			}
			ennemis[i]->update(0);
			ennemis[i]->draw(window);
		}
		collide(player, window);
		player->draw(window);
		if (player->getVie() == 3) {
			window.draw(coeur1);
			window.draw(coeur2);
			window.draw(coeur3);
		}
		else if (player->getVie() == 2) {
			window.draw(coeur1);
			window.draw(coeur2);
		}
		else if (player->getVie() == 1) {
			window.draw(coeur1);
		}
		else {
			window.close();
		}
	}