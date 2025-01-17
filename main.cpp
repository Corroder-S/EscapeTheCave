#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
using namespace sf;

int main() {

	RenderWindow window(VideoMode(600, 900), "Escape the Dungeon");
    
    Player player(10,5,0,100,100);

    window.setFramerateLimit(60);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.update(0);

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}