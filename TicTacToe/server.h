#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


int server();

void drawMap(sf::RenderWindow&);

void isWin(bool& isServerWin, int** mapOfTheGame);

void drawCircle(int, int, std::vector<std::pair<int, int>>&, int** mapOfTheGame, int, int, int);

void drawSquare(int, int, std::vector<std::pair<int, int>>&);
