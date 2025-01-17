#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.cpp"
using namespace sf;

class Player : public Entity {
protected:
	int vie;
	int vitesse;
	int direction;

	int x, y;

	Sprite player_s;
	Texture player_t;
public:

	Player(int vie, int v, int d, int x, int y);

	int getVie();
	int getVitesse();
	int getDirection();
	int getX();
	int getY();
	Sprite* getSprite();

	void setSprite(Sprite sprite);
	void draw(RenderWindow& window) override;
	void update(float deltaTime) override;
	void movePlayer();

};

#endif