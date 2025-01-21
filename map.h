#pragma once
#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "fstream"

using namespace sf;

class Map {
public:

	std::ifstream mapfile("assets/map.txt");
	Texture wall_t;
	Texture floor_t;
	std::vector<RectangleShape*> walls;

};

#endif