#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "map.h"
using namespace sf;

class Player : public Entity {
protected:
	int vie;
	int vitesse;
	int direction;
	int x, y;
	int keycount;

	bool speedup = false;

	Clock animate;
	int i1 = 1;
	int i2 = 1;
	int i3 = 1;
	int i4 = 1;
	Sprite player_s;
	Texture player_t;
public:

	Player(int vie, int v, int d, int x, int y);

	bool getSpeedUp();
	int getVie();
	int getVitesse();
	int getDirection();
	int getX();
	int getY();
	int getKeyCount();
	Sprite* getSprite();

	void setPosition(int nx , int ny);
	void setSpeedUp(bool b);
	void setSprite(Sprite sprite);
	void setVie(int nvie);
	void setKeyCount(int nb);
	void setVitesse(int nb);
	void draw(RenderWindow& window) override;
	void update(float deltaTime) override;
	void movePlayer();

};

#endif