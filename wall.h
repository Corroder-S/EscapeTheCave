#pragma once
#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Wall {
public:
	int x, y;
	int sizex, sizey;
	Texture wall_t;
	RectangleShape wall_rect;

	Wall(int x, int y, int sx, int sy);
};

#endif

