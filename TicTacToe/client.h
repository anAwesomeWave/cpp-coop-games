/*! \file client.h
    \brief TicTacToe client file
    
    Details.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>


/**
* @brief Client win check
*
* The function checks if the client has won the game.
*
* @param mapOfTheGame Game map with turn data
*/
bool isCWin(const std::vector<std::vector<int>>&);
/**
* @brief Creating a window
*
* The function creates a window that will be used in gmae by the client.
*
* @param window Reference on the window that is used to draw the map
* @param w_width Window width
* @param w_heigth Window height
* @param w_name Name that will be given to the window
*/
int setUpCWindow(sf::RenderWindow&, int, int, std::string);
/**
* @brief Drawing a field
*
* The function draws a field in real time.
*
* @param window Reference on the window that is used to draw the map
*
* @return Program exit status
*/
void clientDrawMap(sf::RenderWindow&);

/**
* @brief Drawing a circle
*
* The function draws a circle on the game field
*
* @param x X coordiate of the cell
* @param y Y coordiate of the cell
* @param balls Vector with circle coordinates
*
* @return Program exit status
*/
bool clientDrawCircle(int, int, std::vector<std::pair<int, int>>&);

/**
* @brief Drawing a square
*
* The function draws a square on the game field
*
* @param x X coordiate of the cell
* @param y Y coordiate of the cell
* @param squares Vector with circle coordinates
* @param mapOfTheGame Game map with turn data
* @param turn A toogler of the turn
* @param sendX A reference on the used coordinate
* @param sendX A reference on the used coordinate
*
* @return Program exit status
*/
bool clientDrawSquare(int, int, std::vector<std::pair<int, int>>&, const std::vector<std::vector<int>>&, int&, int&, int&);

/**
* @brief Entry point
*
* Execution of the TicTacToe game for a client user starts here.
*/
void client(uint16_t, std::string&&, uint16_t);

