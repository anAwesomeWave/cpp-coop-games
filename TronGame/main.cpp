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

    Texture bgTexture;
    bgTexture.loadFromFile(BG_IMAGE);
    bgTexture.setSmooth(true);
    Sprite bgSprite(bgTexture);

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
        }
        window.clear();
        window.draw(bgSprite);
        window.display();
    }
    return 0;
}