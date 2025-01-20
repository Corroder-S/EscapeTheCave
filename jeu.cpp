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
	}
}

void Jeu::collide(Player* player, RenderWindow& window) {
	int delayint = delay.getElapsedTime().asSeconds();
	for (int i = 0; i < ennemis.size(); i++) {
		if (player->getSprite()->getGlobalBounds().intersects(ennemis[i]->getSprite()->getGlobalBounds()) && delayint > 1) {
			player->setVie(player->getVie() - 1);
			delay.restart();
		}
	}
	std::cout << player->getVie() << std::endl;
}

void Jeu::manage(Player* player, RenderWindow& window) {
	player->draw(window);
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