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
	bool playing = false;
	bool start = true;
	bool gameover = false;
	bool win = false;
	Clock chrono;
	Clock hitDelay;
	Clock speedupDelay;
	Clock backMenu;
	Texture coeur;
	Texture backt;
	Texture backtalt;
	Texture back_neutral;
	Sprite coeur1;
	Sprite coeur2;
	Sprite coeur3;
	Sprite back;
	Text chrono_aff;
	Text title;
	Text gameovertxt;
	Text backtomenu;
	Text uwon;
	Text starttxt;

	RectangleShape button;
	Font font;
	Map map;

	Jeu();

	std::vector<Ennemi*> ennemis;
	std::vector<Item*> items;

	void generate(int room);

	void collide(Player* player, RenderWindow& window);


	void manage(Player* player, RenderWindow& window);

};

#endif