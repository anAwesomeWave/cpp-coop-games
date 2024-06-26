#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include "settings.h"


using namespace sf;

bool isCWin(const std::vector<std::vector<int>>& mapOfTheGame) {
    if ((mapOfTheGame[0][0] == 2 && mapOfTheGame[0][1] == 2 && mapOfTheGame[0][2] == 2) ||
       (mapOfTheGame[1][0] == 2 && mapOfTheGame[1][1] == 2 && mapOfTheGame[1][2] == 2) ||
       (mapOfTheGame[2][0] == 2 && mapOfTheGame[2][1] == 2 && mapOfTheGame[2][2] == 2) ||
       (mapOfTheGame[0][0] == 2 && mapOfTheGame[1][0] == 2 && mapOfTheGame[2][0] == 2) ||
       (mapOfTheGame[0][1] == 2 && mapOfTheGame[1][1] == 2 && mapOfTheGame[2][1] == 2) ||
       (mapOfTheGame[0][2] == 2 && mapOfTheGame[1][2] == 2 && mapOfTheGame[2][2] == 2) ||
       (mapOfTheGame[0][0] == 2 && mapOfTheGame[1][1] == 2 && mapOfTheGame[2][2] == 2) ||
       (mapOfTheGame[0][2] == 2 && mapOfTheGame[1][1] == 2 && mapOfTheGame[2][0] == 2)) {
            return true;

    }
	return false;
}

void clientDrawMap(RenderWindow& window) {
    for (int i = 200; i < SCR_WIDTH; i += 200) {
            RectangleShape rect1, rect2;
            rect1.setFillColor({0, 0, 0});
            rect1.setSize({2, SCR_HEIGHT});
            rect1.setPosition({static_cast<float>(i), 0});

            rect2.setFillColor({0, 0, 0});
            rect2.setSize({SCR_WIDTH, 2});
            rect2.setPosition({0, static_cast<float>(i)});
            window.draw(rect1);
            window.draw(rect2);
    }
}

bool clientDrawCircle(int x, int y, std::vector<std::pair<int, int>>& balls) {
    if (x < 0 || y < 0) return false;
    if (x < 200) {
        if (y < 200) {
            balls.push_back({50, 50});
        } else if (y < 400) {
            balls.push_back({50, 250});
        } else {
            balls.push_back({50, 450});
        }
    } else if (x < 400) {
        if (y < 200) {
            balls.push_back({250, 50});
        } else if (y < 400) {
            balls.push_back({250, 250});
        } else {
            balls.push_back({250, 450});
        }
    } else {
        if (y < 200) {
            balls.push_back({450, 50});
        } else if (y < 400) {
            balls.push_back({450, 250});
        } else {
            balls.push_back({450, 450});
        }
    }
	return true;
}

bool clientDrawSquare(int x, int y, std::vector<std::pair<int, int>>& squares, const std::vector<std::vector<int>>& mapOfTheGame, int& turn, int& sendX, int& sendY) {
    if (x < 0 || y < 0) return false;
    if (mapOfTheGame[y / 200][x / 200] == 1 || mapOfTheGame[y / 200][x / 200] == 2) {
        sendX = -1;
        sendY = -1;
        turn = 1;
        return false;
    }
    if (x < 200) {
        if (y < 200) {
            squares.push_back({50, 50});
        } else if (y < 400) {
            squares.push_back({50, 250});
        } else {
            squares.push_back({50, 450});
        }
    } else if (x < 400) {
        if (y < 200) {
            squares.push_back({250, 50});
        } else if (y < 400) {
            squares.push_back({250, 250});
        } else {
            squares.push_back({250, 450});
        }
    } else {
        if (y < 200) {
            squares.push_back({450, 50});
        } else if (y < 400) {
            squares.push_back({450, 250});
        } else {
            squares.push_back({450, 450});
        }
    }
    // mapOfTheGame[y / 200][x / 200] = 2;
    sendX = x; sendY = y;
    turn = 0;
	return true;
}

int setUpCWindow(RenderWindow& window, int w_width, int w_height, std::string w_name) {
    if (w_width % 12 != 0 || w_height % 12 != 0) {
        return 1;
    }
    window.create(VideoMode(w_width, w_height), w_name, Style::Titlebar | Style::Close);
    return 0;
}

void client(uint16_t port, std::string&& opponent_ip, uint16_t opponent_port)
{
	sf::RenderWindow window;
    setUpCWindow(window, SCR_WIDTH, SCR_HEIGHT, "TicTacToeClient");

    std::vector<std::pair<int, int>> balls;
    std::vector<std::pair<int, int>> squares;
    Texture texture1, texture2;
    texture1.loadFromFile(O_TEXTURE);
    texture2.loadFromFile(X_TEXTURE);
    int turn = 0; // 0 - server, 1 - client
    std::vector<std::vector<int>> mapOfTheGame(3, std::vector<int>(3));

    bool isServerWin = false;
    bool isClientWin = false;

    UdpSocket socket;
    socket.bind(port);
    socket.setBlocking(false);

    Clock clock;
    Time timer;

    int sendX = -1; int sendY = -1;

    while (window.isOpen()){
        timer += clock.getElapsedTime();
        clock.restart();
        ///END_OF_THE_GAME///
        if (isServerWin || isClientWin) {
            while (window.isOpen()) {
                Font font;
                font.loadFromFile(FONT);
                Text text;
                text.setFont(font);
                text.setFillColor(Color::Blue);
                text.setPosition({200, 200});
                if (isClientWin) {
                    text.setString("Client win!");
                } else {
                    text.setString("Server win!");
                }
                Event e;
                while (window.pollEvent(e)) {
                    if(e.type == Event::Closed) {
                        window.close();
                    }
                }
                window.clear(Color::White);
                window.draw(text);
                window.display();
            }
        }

        sf::Event event;
        window.clear(Color::White);
        Packet packet;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left && turn && !isServerWin && !isClientWin) {
                    int x = Mouse::getPosition(window).x;
                    int y = Mouse::getPosition(window).y;
                    if (clientDrawSquare(x, y, squares, mapOfTheGame, turn, sendX, sendY) == true) {
                        mapOfTheGame[y / 200][x / 200] = 2;
                    }

                    ///SEND///
                    isClientWin = isCWin(mapOfTheGame);
                    if (timer.asSeconds() >= DELAY) {
                        timer = Time::Zero;
                        isClientWin = isCWin(mapOfTheGame);
                        packet << sendX << sendY << turn << isClientWin;
                        socket.send(packet, opponent_ip, opponent_port);
                    }
                }
            }
        }
        packet.clear();

        ///RECEIVE///
        IpAddress senderIp;
        unsigned short senderPort;

        if (socket.receive(packet, senderIp, senderPort) == Socket::Status::Done) {
            int senderX, senderY;
            packet >> senderX >> senderY >> turn >> isServerWin;
            mapOfTheGame[senderY / 200][senderX / 200] = 1;
            clientDrawCircle(senderX, senderY, balls);
        }


        for (auto i : balls) {
            Sprite s;
            s.setTexture(texture1);
            s.setPosition({static_cast<float>(i.first), static_cast<float>(i.second)});
            window.draw(s);
        }
        for(auto i : squares) {
            Sprite s;
            s.setTexture(texture2);
            s.setPosition({static_cast<float>(i.first), static_cast<float>(i.second)});
            window.draw(s);
        }
        clientDrawMap(window);
        window.display();
    }
}
