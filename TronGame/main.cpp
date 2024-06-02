#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "player.hpp"
#include "settings.hpp"

using namespace sf;
int main() {
    srand(time(NULL));
    RenderWindow window({SCR_WIDTH, SCR_HEIGHT}, "Tron Game");
    Clock clock;
    Time timer;

    bool game = true;
    int whoLose = 0;

    while(window.isOpen()) {
        timer += clock.getElapsedTime();
        clock.restart();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            window.clear();
            window.display();
        }
    }
    return 0;
}