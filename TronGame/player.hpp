/*! \file player.hpp
\brief Tron player file

    Details.
*/


#pragma once

class Player {
private:
    /**
    * Coordinates of the player's circle.
    */
    float x, y;
    /**
    * Radius of the player's circle.
    */
    int radius = 1;
    /**
    * Speed of the player's circle.
    */
    int speed = 1;
    /**
    * Direction of the player's circle.
    */
    int dir;

    sf::CircleShape circle;
public:
    /**
    * @brief Creating a class
    *
    * The function is a constructor of the class.
    *
    * @param X X coordinate
    * @param Y Y coordinate
    * @param color A color of the player
    */
    Player(float X, float Y, sf::Color color);

    /**
    * @brief Changing coordinates
    *
    * The function changes coordinates depending on the direction.
    */
    void move();

    /**
    * @brief Drawing a player
    *
    * The function draws a user circle on the game field.
    *
    * @param window Window that is used in the game.
    */
    void draw(sf::RenderWindow& window);

    /**
    * @brief Changing a direction
    *
    * The function changes a direction in depend of direction.
    *
    * @param n Number of direction.
    */
    void setDir(int n);

    /**
    * @brief Returning a direction
    *
    * The function returns a direction number.
    *
    * @return A direction number.
    */
    int getDir() const;

    /**
    * @brief Returning a horizontal coordinate
    *
    * The function returns a horizontal coordinate.
    *
    * @return A horizontal coordinate.
    */
    float getX() const;

    /**
    * @brief Returning a vertical coordinate
    *
    * The function returns a vertical coordinate.
    *
    * @return A hvertical coordinate.
    */
    float getY() const;
};