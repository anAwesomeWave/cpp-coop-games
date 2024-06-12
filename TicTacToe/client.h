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
* @param isClientWin Reference on the boolean variable of the client's win
* @param mapOfTheGame Game map with turn data
*/
void isCWin(bool&, int[3][3]);

/**
* @brief Drawing a field
*
* The function draws a field in real time.
*
* @param window Reference on the window that is used to draw the map
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
void clientDrawCircle(int, int, std::vector<std::pair<int, int>>&);

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
void clientDrawSquare(int, int, std::vector<std::pair<int, int>>&, int[3][3], int&, int&, int&);

/**
* @brief Entry point
*
* Execution of the TicTacToe game for a client user starts here.
*/
void client();

