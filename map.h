#pragma once
#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "wall.h"
#include "floor.h"
#include "door.h"

using namespace sf;

class Map {
public:

	std::ifstream mapfile;
	std::vector<Wall*> walls;
	std::vector<Floor*> floors;
	std::vector<Door*> doors;


	Map();
};

#endif