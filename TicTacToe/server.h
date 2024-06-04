#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <cstdint>
#include <string>


void server(uint16_t port, std::string&& o_ip, uint16_t o_port);

void drawMap(sf::RenderWindow& window, int y_block_sz, int x_block_sz);

bool isWin(const std::vector<std::vector<int>> &mapOfTheGame);

void drawObjects(
    const std::vector<std::vector<int>>& mapOfTheGame,
    sf::RenderWindow& window,
    sf::Texture& texture1,
    sf::Texture& texture2,
    int y_size,
    int x_size
);


int processCLick(int x, int y, int x_div, int y_div, int turn, std::vector<std::vector<int>>& mapOfTheGame);

int setUpWindow(sf::RenderWindow& window, int w_width, int w_height, std::string name);
