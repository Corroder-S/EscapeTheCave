#include <iostream>
#include <SFML/Graphics.hpp>
#include "jeu.h"
#include "player.h"
#include "ennemis.h"
#include "chaserEnemy.h"
#include "map.h"
#include "patrollingEnemy.h"
#include <ctime>

using namespace sf;

int main() {

    
    srand(time(NULL));
    Jeu jeu;

	RenderWindow window(VideoMode(600, 900), "Escape the Dungeon");
    
    Player player(3,5,0,100,100);
    jeu.generate(1);
    

    window.setFramerateLimit(60);
    Map map;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.update(0);
        window.clear();
        for (int i = 0; i < map.walls.size(); i++) {
            window.draw(map.walls[i]->wall_rect);
        }
        for (int i = 0; i < map.floors.size(); i++) {
            window.draw(map.floors[i]->floor_rect);
        }
        jeu.manage(&player, window);
        window.display();
    }

    return 0;
}