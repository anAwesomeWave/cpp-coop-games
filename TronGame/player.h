/*! \file player.hpp
\brief Tron player file

    File that contains player class.
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
    * @param rad Radius of the player
    * @param speed Speed of the player
    */
    Player(float X, float Y, sf::Color color, int rad=1, int speed=1);

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

    /**
    * @brief Returns a direction
    *
    * The function returns radius.
    *
    * @return radius field.
    */
    int getRadius() const;

    /**
    * @brief Changing speed
    *
    * The function changes a spped.
    *
    * @param speed current speed {1, 2, 3, ...}.
    */
    void setSpeed(int speed);

    /**
    * @brief Returns a speed
    *
    * The function returns speed.
    *
    * @return speed field.
    */
    int getSpeed() const;
};
