#pragma once
#ifndef JEU_H
#define JEU_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "ennemis.h"
#include "patrollingEnemy.h"
#include "chaserEnemy.h"

class Jeu {
public:
	Clock delay;
	Texture coeur;
	Sprite coeur1;
	Sprite coeur2;
	Sprite coeur3;

	Jeu();

	std::vector<Ennemi*> ennemis;

	void generate(int room);

	void collide(Player* player, RenderWindow& window);


	void manage(Player* player, RenderWindow& window);

};

#endif