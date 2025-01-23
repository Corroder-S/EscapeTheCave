#pragma once
#ifndef DOOR_H
#define DOOR_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Door {
public:
	int x, y;
	int sizex, sizey;
	Texture door_t;
	RectangleShape door_rect;
	bool open = false;

	Door(int x, int y, int sx, int sy);
};

#endif