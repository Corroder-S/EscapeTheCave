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

void Jeu::collide(Player* player, RenderWindow& window) {
	int hitDelayint = hitDelay.getElapsedTime().asSeconds();

	for (int i = 0; i < ennemis.size(); i++) {
		if (player->getSprite()->getGlobalBounds().intersects(ennemis[i]->getSprite()->getGlobalBounds()) && hitDelayint > 1) {
			player->setVie(player->getVie() - 1);
			hitDelay.restart();
		}
	}

	for (auto it = items.begin(); it != items.end(); ) {
		if (player->getSprite()->getGlobalBounds().intersects((*it)->getSprite()->getGlobalBounds())) {
			(*it)->interact(*player);
			if ((*it)->getType() == 1) {
				speedupDelay.restart();
			}
			std::cout << "collide" << std::endl;

			delete* it;
			it = items.erase(it);
		}
		else {
			++it;
		}
	}
}


void Jeu::manage(Player* player, RenderWindow& window) {
	int speedupDelay_int = speedupDelay.getElapsedTime().asSeconds();
	if (player->getSpeedUp() && speedupDelay_int > 2) {
		player->setVitesse((player->getVitesse() / 1.5) +1 );
		player->setSpeedUp(false);
	}
	
	std::cout << "Vitesse" << player->getVitesse() << std::endl;

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
	else if (player->getVie() == 1){
		window.draw(coeur1);
	}
	else {
		window.close();
	}
}