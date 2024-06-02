#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


void isCWin(bool&, int[3][3]);

void clientDrawMap(sf::RenderWindow&);

void clientDrawCircle(int, int, std::vector<std::pair<int, int>>&);

void clientDrawSquare(int, int, std::vector<std::pair<int, int>>&, int[3][3], int&, int&, int&);

void client();

