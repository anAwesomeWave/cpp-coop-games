/*! \file game.h
\brief Tron game file

    Details.
*/


#pragma once
#include <vector>


class Player;

class RenderWindow;
/**
* @brief Game cycle
*
* The function is the main game cycle.
*
* @return Program exit status
*/
int gameLoop();
/**
* @brief End of the game logic
*
* The function checks if there are a winner on the field.
*
* @param p1 The first player
* @param p2 The second player
* @param field Tha game field
*
* @return Game end status
*/
int endOfGame(const Player& p1, const Player& p2, std::vector<std::vector<int>>& field);
/**
* @brief Win message
*
* The function creates a window whis congrats to game winner.
*
* @param window Game window, witch will be used in drawing
* @param whoLOse Game number that has lost
*/
void handleEndOfGame(RenderWindow& window, int whoLose);
