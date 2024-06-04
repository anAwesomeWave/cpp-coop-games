#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


void server();

void drawMap(sf::RenderWindow &);

bool isWin(const std::vector<std::vector<int>> &mapOfTheGame);

int drawCircle(int, int, std::vector<std::pair<int, int>>&, std::vector<std::vector<int>>& , int&, int&);

void drawSquare(int, int, std::vector <std::pair<int, int>> &);
