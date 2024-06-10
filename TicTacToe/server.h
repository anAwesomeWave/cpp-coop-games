#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <cstdint>
#include <string>

/*! \file server.h
    \brief A Documented file.
    
    Server side logic of the TicTacToe.
*/

/**
* @brief Entry point
*
* Execution of the TicTacToe game for a server user starts here.
*
* @param port Port of the server
* @param opponent_ip String representin an IP addr. of the opponent.
* @param opponent_port Port of the opponent
*/
void server(uint16_t port, std::string&& o_ip, uint16_t o_port);

/**
* @brief Drawing a map
*
* The function draws a map that is used during the game.
*
* @param window A reference on game field
* @param y_block_ez Size of the field cell vertical side
* @param x_block_ez Size of the field cell horizontal side
*/
void drawMap(sf::RenderWindow& window, int y_block_sz, int x_block_sz);

/**
* @brief Server win check
*
* The function checks if the server has won the game.
*
* @param mapOfTheGame Game map with turn data
*
* @return True - server has won, false - server has not won yet
*/
bool isWin(const std::vector<std::vector<int>> &mapOfTheGame);

/**
* @brief Drawing a circle or a cross
*
* The function draws a circle or a cross depending on the turn
*
* @param mapOfTheGame Game map with turn data
* @param window A reference on game field
* @param texture1 A cross texture
* @param texture1 A circle texture
* @param y_size A vertical size of an pasting input
* @param x_size A horizontal size of an pasting input
*/
void drawObjects(
    const std::vector<std::vector<int>>& mapOfTheGame,
    sf::RenderWindow& window,
    sf::Texture& texture1,
    sf::Texture& texture2,
    int y_size,
    int x_size
);

/**
* @brief Click treatment
*
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
int processCLick(int x, int y, int x_div, int y_div, int turn, std::vector<std::vector<int>>& mapOfTheGame);


/**
* @brief Creating a game window
*
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
int setUpWindow(sf::RenderWindow& window, int w_width, int w_height, std::string name);
