#pragma once
#ifndef FLOOR_H
#define FLOOR_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Floor {
public:
	int x, y;
	int sizex, sizey;
	Texture floor_t;
	RectangleShape floor_rect;

	Floor(int x, int y, int sx, int sy);

};

#endif // !FLOOR_H
