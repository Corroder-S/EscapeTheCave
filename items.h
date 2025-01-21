#pragma once
#ifndef ITEMS_H
#define ITEMS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Interactable.h"
#include "entity.h"


using namespace sf;

class Item : public Interactable,  public Entity{
protected:
	int x;
	int y;
	int type;
	Sprite item_s;
	Texture item_t;
public:

	Item(int x, int y, int t);

	int getType();
	Sprite* getSprite();

	void update(float deltatime) override;

	void draw(RenderWindow& window) override;

	void interact(Player& player) override;
};

#endif
