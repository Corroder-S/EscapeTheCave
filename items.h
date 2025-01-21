#pragma once
#ifndef ITEMS_H
#define ITEMS_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Item {
protected:
	int x;
	int y;
	int type;
	Sprite item_s;
	Texture item_t;
public:

	Item(int x, int y, int t);
	

};

#endif
