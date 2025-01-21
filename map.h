#pragma once
#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Map {
public:

	Texture wall_t;
	Texture floor_t;
	std::vector<RectangleShape*> walls;

};

#endif