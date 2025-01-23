#include "map.h"

Map::Map() {
	mapfile.open("assets/map.txt");
	std::string line;
	
	int y = 0;

	while (std::getline(mapfile, line)) {
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '#') {
				walls.push_back(new Wall(i*50, y*50, 50, 50));
			}
			else if (line[i] == ' ') {
				floors.push_back(new Floor(i * 50, y * 50, 50, 50));
			}
		}
		y++;
		std::cout << std::endl;

	}
}