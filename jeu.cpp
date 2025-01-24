#include "jeu.h"

Jeu::Jeu() {
	if (!coeur.loadFromFile("assets/coeur.png"))
		return;
	coeur1.setTexture(coeur);
	coeur2.setTexture(coeur);
	coeur3.setTexture(coeur);
	coeur1.setPosition(50, 5);
	coeur2.setPosition(100, 5);
	coeur3.setPosition(150, 5);

	font.loadFromFile("assets/Daydream.ttf");

	chrono_aff.setFont(font);
	chrono_aff.setPosition(275, 0);
	chrono_aff.setCharacterSize(30);

	title.setFont(font);
	title.setPosition(50, 50);
	title.setFillColor(Color::Cyan);
	title.setOutlineThickness(10);
	title.setOutlineColor(Color::Black);
	title.setString("Escape The \n\n		 Cave");
	title.setCharacterSize(50);

	button.setSize(Vector2f(332, 550));
	button.setPosition(133, 350);

	starttxt.setFont(font);
	starttxt.setPosition(190, 570);
	starttxt.setFillColor(Color::White);
	starttxt.setCharacterSize(40);
	starttxt.setString("START");

	if (!backt.loadFromFile("assets/background.png"))
		return;
	if (!backtalt.loadFromFile("assets/background_open.png"))
		return;
	back.setTexture(backt);
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
		if (player->getSprite()->getGlobalBounds().intersects(map.walls[i]->wall_rect.getGlobalBounds()) && player->getDirection() == 1) {
			player->setPosition(player->getX(), map.walls[i]->wall_rect.getPosition().y + 50);
		}
		else if (player->getSprite()->getGlobalBounds().intersects(map.walls[i]->wall_rect.getGlobalBounds()) && player->getDirection() == 2) {
			player->setPosition(map.walls[i]->wall_rect.getPosition().x - 40 , player->getY());
		}
		else if (player->getSprite()->getGlobalBounds().intersects(map.walls[i]->wall_rect.getGlobalBounds()) && player->getDirection() == 3) {
			player->setPosition(player->getX(), map.walls[i]->wall_rect.getPosition().y - 40);
		}
		else if (player->getSprite()->getGlobalBounds().intersects(map.walls[i]->wall_rect.getGlobalBounds()) && player->getDirection() == 4) {
			player->setPosition(map.walls[i]->wall_rect.getPosition().x + 50, player->getY());
		}
	}

	for (int i = 0; i < map.doors.size(); i++) {
		if (!map.doors[i]->open) {
			if (player->getSprite()->getGlobalBounds().intersects(map.doors[i]->door_rect.getGlobalBounds()) && player->getDirection() == 1) {
				player->setPosition(player->getX(), map.doors[i]->door_rect.getPosition().y + 50);
				if (player->getKeyCount() > 0) {
					map.doors[i]->open = true;
					player->setKeyCount(player->getKeyCount() - 1);
				}
			}
			else if (player->getSprite()->getGlobalBounds().intersects(map.doors[i]->door_rect.getGlobalBounds()) && player->getDirection() == 2) {
				player->setPosition(map.doors[i]->door_rect.getPosition().x - 40, player->getY());
				if (player->getKeyCount() > 0) {
					map.doors[i]->open = true;
					player->setKeyCount(player->getKeyCount() - 1);
				}
			}
			else if (player->getSprite()->getGlobalBounds().intersects(map.doors[i]->door_rect.getGlobalBounds()) && player->getDirection() == 3) {
				player->setPosition(player->getX(), map.doors[i]->door_rect.getPosition().y - 40);
				if (player->getKeyCount() > 0) {
					map.doors[i]->open = true;
					player->setKeyCount(player->getKeyCount() - 1);
				}
			}
			else if (player->getSprite()->getGlobalBounds().intersects(map.doors[i]->door_rect.getGlobalBounds()) && player->getDirection() == 4) {
				player->setPosition(map.doors[i]->door_rect.getPosition().x + 50, player->getY());
				if (player->getKeyCount() > 0) {
					map.doors[i]->open = true;
					player->setKeyCount(player->getKeyCount() - 1);
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



	void Jeu::manage(Player * player, RenderWindow & window) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (start) {
			window.draw(button);
			window.draw(back);
			if (button.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				back.setTexture(backtalt);
				window.draw(starttxt);
				if (Mouse::isButtonPressed(Mouse::Left)) {
					start = false;
					playing = true;
					chrono.restart();
				}
			}
			else (back.setTexture(backt));
			window.draw(title);
			
		}
		if (playing) {
			int chronoint = chrono.getElapsedTime().asSeconds();
			chrono_aff.setString(std::to_string(30 - chronoint));
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
			window.draw(chrono_aff);
		}
	}