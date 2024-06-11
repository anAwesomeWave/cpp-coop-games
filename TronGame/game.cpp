#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "settings.hpp"

using namespace sf;
using std::vector;



int endOfGame(const Player& p1, const Player& p2, vector<vector<int>>& field) {
    // 1 - player1 lose , 2- player 2, 0 - nobody
    if ((field[int(p1.getY())][int(p1.getX())] == 1 && p1.getDir() != -1) ||
        field[int(p1.getY())][int(p1.getX())] == 2
    ) {
            return 1;
    }
    if ((field[int(p2.getY())][int(p2.getX())] == 2 && p2.getDir() != -1) ||
        field[int(p2.getY())][int(p2.getX())] == 1
    ) {
            return 2;
    }
    return 0;
}

void handleEndOfGame(RenderWindow& window, int whoLose) {
    Font font;
    font.loadFromFile(FONT);
    Text text;
    text.setFont(font);
    text.setPosition({SCR_WIDTH / 2 - 200, 100});
    if(whoLose == 1) {
        text.setFillColor(Color::Green);
    } else {
        text.setFillColor(Color::Blue);
    }
    text.setString("You win!");
    window.draw(text);
}

int gameLoop() {

    vector<vector<int>> field(SCR_HEIGHT + 1, vector<int>(SCR_WIDTH + 1, 0));
    srand(time(NULL));
    RenderWindow window({SCR_WIDTH, SCR_HEIGHT}, "Tron Game");
    Player player2(rand() % SCR_WIDTH, rand() % SCR_HEIGHT, {0, 255, 0});
    Player player1(rand() % SCR_WIDTH, rand() % SCR_HEIGHT, {0, 0, 255});
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
            if(event.type == Event::KeyPressed) {
                ///PLAYER 1///
                if(event.key.code == Keyboard::A && player1.getDir() != 2)
                    player1.setDir(0);
                if(event.key.code == Keyboard::W && player1.getDir() != 3)
                    player1.setDir(1);
                if(event.key.code == Keyboard::D && player1.getDir() != 0)
                    player1.setDir(2);
                if(event.key.code == Keyboard::S && player1.getDir() != 1)
                    player1.setDir(3);
                ///PLAYER 2///
                if(event.key.code == Keyboard::Left && player2.getDir() != 2)
                    player2.setDir(0);
                if(event.key.code == Keyboard::Up && player2.getDir() != 3)
                    player2.setDir(1);
                if(event.key.code == Keyboard::Right && player2.getDir() != 0)
                    player2.setDir(2);
                if(event.key.code == Keyboard::Down && player2.getDir() != 1)
                    player2.setDir(3);
            }
        }
        window.clear();
        window.draw(bgSprite);

        if(game) {
            if(timer.asSeconds() >= DELAY) {
                player1.move();
                player2.move();
                whoLose = endOfGame(player1,player2, field);
                if (whoLose) {
                    game = false;
                }
                field[int(player1.getY())][int(player1.getX())] = 1;
                field[int(player2.getY())][int(player2.getX())] = 2;
                timer = sf::seconds(0.f);
            }
        } else {
            handleEndOfGame(window, whoLose);
        }
        for(int i = 0; i <= SCR_HEIGHT; i ++) {
            for(int j = 0; j <= SCR_WIDTH; j ++) {
                if(field[i][j] == 1) {
                    CircleShape c;
                    c.setOrigin(2, 2);
                    c.setPosition({j, i});
                    c.setRadius(1);
                    c.setFillColor({0, 0, 255});
                    window.draw(c);
                }
                if(field[i][j] == 2) {
                    CircleShape c;
                    c.setOrigin(2, 2);
                    c.setPosition({j, i});
                    c.setRadius(1);
                    c.setFillColor({0, 255, 0});
                    window.draw(c);
                }
            }
        }

        player1.draw(window);
        player2.draw(window);
        window.display();
    }
    return 0;
}
