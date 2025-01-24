#include <iostream>
#include <SFML/Graphics.hpp>
#include "jeu.h"
#include "player.h"
#include <ctime>

using namespace sf;

int main() {

    
    srand(time(NULL));
    Jeu jeu;

	RenderWindow window(VideoMode(600, 900), "Escape the Dungeon");
    
    Player player(3,4,0,50,50);
    jeu.generate(1);
    

    window.setFramerateLimit(60);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.update(0);
        window.clear();
        
        jeu.manage(&player, window);
        window.display();
    }

    return 0;
}