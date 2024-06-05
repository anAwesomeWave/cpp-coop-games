#include <cstdint>
#include <iostream>
#include <sys/types.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "settings.hpp"
#include "server.h"


using namespace sf;

/**
* @brief Server win check
*
* The function checks if the server has won the game.
*
* @param mapOfTheGame Game map with turn data
*
* @return True - server has won, false - server has not won yet
*/
bool isWin(const std::vector<std::vector<int>>& mapOfTheGame) {
    if((mapOfTheGame[0][0] == 1 && mapOfTheGame[0][1] == 1 && mapOfTheGame[0][2] == 1) ||
       (mapOfTheGame[1][0] == 1 && mapOfTheGame[1][1] == 1 && mapOfTheGame[1][2] == 1) ||
       (mapOfTheGame[2][0] == 1 && mapOfTheGame[2][1] == 1 && mapOfTheGame[2][2] == 1) ||
       (mapOfTheGame[0][0] == 1 && mapOfTheGame[1][0] == 1 && mapOfTheGame[2][0] == 1) ||
       (mapOfTheGame[0][1] == 1 && mapOfTheGame[1][1] == 1 && mapOfTheGame[2][1] == 1) ||
       (mapOfTheGame[0][2] == 1 && mapOfTheGame[1][2] == 1 && mapOfTheGame[2][2] == 1) ||
       (mapOfTheGame[0][0] == 1 && mapOfTheGame[1][1] == 1 && mapOfTheGame[2][2] == 1) ||
       (mapOfTheGame[0][2] == 1 && mapOfTheGame[1][1] == 1 && mapOfTheGame[2][0] == 1)) {
        return true;
    }
    return false;
}

/**
* @brief Drawing a map
*
* The function draws a map that is used during the game.
*
* @param window A reference on game field
* @param y_block_ez Size of the field cell vertical side
* @param x_block_ez Size of the field cell horizontal side
*/
void drawMap(RenderWindow& window, int y_block_sz, int x_block_sz) {
    int windowH = window.getSize().y;
    int windowW = window.getSize().x;
    // can test window.getSize after calling this func
    for(int x_line = x_block_sz; x_line < windowW; x_line += x_block_sz) {
        RectangleShape rect1;
        rect1.setFillColor({0, 0, 0});
        rect1.setSize({2, windowH});
        rect1.setPosition({x_line, 0});
        window.draw(rect1);
    }

    for(int y_line = y_block_sz; y_line < windowH; y_line += y_block_sz) {
        RectangleShape rect2;
        rect2.setFillColor({0, 0, 0});
        rect2.setSize({windowW, 2});
        rect2.setPosition({0, y_line});
        window.draw(rect2);
    }
}

/**
* @brief Drawing a circle or a cross
* The function draws a circle or a cross depending on the turn
*
* @param mapOfTheGame Game map with turn data
* @param window A reference on game field
* @param texture1 A cross texture
* @param texture1 A circle texture
* @param y_size A vertical size of an pasting input
* @param x_size A horizontal size of an pasting input
*/
void drawObjects(const std::vector<std::vector<int>>& mapOfTheGame, RenderWindow& window, Texture& texture1, Texture& texture2, int y_size, int x_size) {
    for (int y_ind = 0; y_ind < mapOfTheGame.size(); y_ind++) {
        for (int x_ind = 0; x_ind < mapOfTheGame[x_ind].size(); x_ind++) {
            if (mapOfTheGame[y_ind][x_ind] != 0) {
                Sprite s;
                if (mapOfTheGame[y_ind][x_ind] == 1) {
                    s.setTexture(texture1);
                } else {
                    s.setTexture(texture2);
                }
                s.setPosition({x_ind * x_size + TEXTURE_SHIFT, y_ind * y_size + TEXTURE_SHIFT});
                window.draw(s);
            }
        }
    }
}

/**
* @brief Click treatment
* Set value of the cell of the mapOfTheGame parameter depending on the x, y position of Mouse and turn parity.
*
* @param x X coordinate of click
* @param y Y coordinate of click
* @param x_div Horizontal size of a field cell
* @param y_div Vertical size of a field cell
* @param turn Number of turn to pick a texture [0 - server, 1 - client]
* @param mapOfTheGame Game map with turn data.
*
* @return Program exit status
*/
int processCLick(int x, int y, int x_div, int y_div, int turn, std::vector<std::vector<int>>& mapOfTheGame) {
    if (x < 0 || y < 0 || mapOfTheGame[y / y_div][x / x_div] != 0){
        return 1;
    }
    mapOfTheGame[y / y_div][x / x_div] = turn + 1;
    // server - > 1
    // client -> 2
    return 0;
}

/**
* @brief Creating a game window
* The function creates a game server window. If the provided width and height of a window is not
* divisible by 12 return an error code 1.
*
* @param window A reference on game field
* @param w_width Window width
* @param w_height Window height
* @param name Name of tha game window.
*
* @return Program exit status
*/
int setUpWindow(RenderWindow& window, int w_width, int w_height, std::string name) {
    // field is 3x3 and sprit will be placed at first quarter of each block
    if (w_width % 12 != 0 || w_height % 12 != 0) {
        return 1;
    }
    window.create(VideoMode(w_width, w_height), name, Style::Titlebar | Style::Close);
    return 0;
}

/**
* @brief Entry point
*
* Execution of the TicTacToe game for a server user starts here.
*
* @param port Port of the server
* @param opponent_ip String representin an IP addr. of the opponent.
* @param opponent_port Port of the opponent
*/
void server(uint16_t port, std::string&& opponent_ip, uint16_t opponent_port)
{
    sf::RenderWindow window;
    setUpWindow(window, SCR_WIDTH, SCR_HEIGHT, "TicTacToeServer");
    // setUpWindow(window, 900, 1200, "TicTacToeServer");


    int x_block_size, y_block_size;
    x_block_size = window.getSize().x / 3;
    y_block_size = window.getSize().y / 3;
    int turn = 0; // 0 - server, 1 - client
    std::vector<std::vector<int>> mapOfTheGame(3, std::vector<int>(3));

    std::vector<std::pair<int, int>> balls;
    std::vector<std::pair<int, int>> squares;
    Texture texture1, texture2;
    texture1.loadFromFile(O_TEXTURE);
    texture2.loadFromFile(X_TEXTURE);

    UdpSocket socket;
    socket.bind(port);
    socket.setBlocking(false);

    Clock clock;
    Time timer;

    int sendX = -1; int sendY = -1;
    bool isServerWin = false;
    bool isClientWin = false;

    while (window.isOpen()){
        timer += clock.getElapsedTime();
        clock.restart();
        sf::Event event;
        window.clear(Color::White);
        Packet packet;
        timer += clock.getElapsedTime();
        clock.restart();
        ///END_OF_THE_GAME///
        if (isServerWin || isClientWin) {
            while(window.isOpen()) {
                Font font;
                font.loadFromFile(FONT);
                Text text;
                text.setFont(font);
                text.setFillColor(Color::Blue);
                text.setPosition({200, 200});
                if(isClientWin) {
                    text.setString("Client win!");
                } else {
                    text.setString("Server win!");
                }
                Event e;
                while(window.pollEvent(e)) {
                    if(e.type == Event::Closed) {
                        window.close();
                    }
                }
                window.clear(Color::White);
                window.draw(text);
                window.display();
            }
        }

        while (window.pollEvent(event)){
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.key.code == Mouse::Left && turn == 0 && !isServerWin && !isClientWin) {
                    if (processCLick(Mouse::getPosition(window).x, Mouse::getPosition(window).y, x_block_size, y_block_size, turn, mapOfTheGame) == 0) {
                        turn = 1;
                        sendX = Mouse::getPosition(window).x;
                        sendY = Mouse::getPosition(window).y;
                    }
                    isServerWin = isWin(mapOfTheGame);
                    if(timer.asSeconds() >= DELAY) {
                        timer = Time::Zero;
                        packet << sendX << sendY << turn << isServerWin;
                        socket.send(packet, opponent_ip, opponent_port);
                        packet.clear();
                    }
                }
            }
        }

        ///RECEIVE///
        IpAddress senderIp;
        unsigned short senderPort;

        if (socket.receive(packet, senderIp, senderPort) == Socket::Status::Done) {
            int senderX, senderY;
            packet >> senderX >> senderY >> turn >> isClientWin;
            processCLick(
                senderX,
                senderY,
                x_block_size,
                y_block_size,
                2 - turn,
                mapOfTheGame
            );

        }

        drawObjects(mapOfTheGame, window, texture1, texture2, y_block_size, x_block_size);
        drawMap(window, y_block_size, x_block_size);
        window.display();
    }
}
