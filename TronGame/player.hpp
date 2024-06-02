//
// Created by tim on 19.05.24.
//

#ifndef PLAYERCLASS_HPP_INCLUDED
#define PLAYERCLASS_HPP_INCLUDED

class Player {
private:
    float x, y;
    int radius = 1;
    int speed = 1;
    int dir;
    sf::CircleShape circle;
public:
    Player(float X, float Y, sf::Color color);
    void move();
};

#endif // PLAYERCLASS_HPP_INCLUDED