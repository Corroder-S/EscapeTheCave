#pragma once
#ifndef JEU_H
#define JEU_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "ennemis.h"
#include "patrollingEnemy.h"
#include "chaserEnemy.h"
#include "items.h"
#include "potion.h"
#include "key.h"
#include "map.h"

class Jeu {
public:
	Clock hitDelay;
	Clock speedupDelay;
	Texture coeur;
	Sprite coeur1;
	Sprite coeur2;
	Sprite coeur3;
	Map map;

	Jeu();

	std::vector<Ennemi*> ennemis;
	std::vector<Item*> items;

	void generate(int room);

	void collide(Player* player, RenderWindow& window);


	void manage(Player* player, RenderWindow& window);

};

#endif