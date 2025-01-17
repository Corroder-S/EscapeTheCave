#pragma once
#ifndef ENNEMIS_H
#define ENNEMIS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.cpp"

using namespace sf;

class Ennemi: public Entity {
protected:
	int vie;
	int vitesse;
	int direction;
	int x;
	int y;
	Sprite ennemi_s;
public:

	Ennemi(int vie, int v, int d, int x, int y);

	int getVie();
	int getVitesse();
	int getDirection();
	int getX();
	int getY();
	Sprite* getSprite();

	virtual void move_Ennemi() = 0;
	
	void draw(RenderWindow& window) override;
	void update(float deltaTime) override;
};

#endif
