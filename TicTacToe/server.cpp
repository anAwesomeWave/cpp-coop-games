#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "settings.hpp"
#include "server.h"

using namespace sf;


void drawMap(RenderWindow& window) {
    for(int i = 200; i < SCR_WIDTH; i += 200) {
            RectangleShape rect1, rect2;
            rect1.setFillColor({0, 0, 0});
            rect1.setSize({2, SCR_HEIGHT});
            rect1.setPosition({i, 0});

            rect2.setFillColor({0, 0, 0});
            rect2.setSize({SCR_WIDTH, 2});
            rect2.setPosition({0, i});
            window.draw(rect1);
            window.draw(rect2);
    }
}


int server(){
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "TicTacToeServer");
    while (window.isOpen()){
        window.clear(Color::White);
	Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed) {
                window.close();
            }
	}
        drawMap(window);
        window.display();
    }
    return 0;
}
