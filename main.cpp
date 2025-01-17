#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "chaserEnemy.h"
using namespace sf;

int main() {

	RenderWindow window(VideoMode(600, 900), "Escape the Dungeon");
    
    Player player(10,5,0,100,100);
    ChaserEnemy test(2, 500, 500);

    window.setFramerateLimit(60);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.update(0);

        test.move_Ennemi(player.getX(), player.getY());
        test.update(0);

        window.clear();
        test.draw(window);
        player.draw(window);
        window.display();
    }

    return 0;
}