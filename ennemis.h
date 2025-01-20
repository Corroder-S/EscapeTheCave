#pragma once
#ifndef ENNEMIS_H
#define ENNEMIS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"

using namespace sf;

class Ennemi: public Entity {
protected:
	int type;
	int vie;
	int vitesse;
	int direction;
	int x;
	int y;
	Sprite ennemi_s;
	Texture ennemi_t;
public:

	Ennemi(int vie, int v, int d, int x, int y, int t);

	int getType();
	Vector2f getPosition();
	int getVie();
	int getVitesse();
	int getDirection();
	int getX();
	int getY();
	Sprite* getSprite();

	void setPosition(Vector2f pos);

	virtual void move_Enemy(int x_player, int y_player) = 0;
	virtual void move_Enemy() = 0;
	
	void draw(RenderWindow& window) override;
	void update(float deltaTime) override;
};

#endif
