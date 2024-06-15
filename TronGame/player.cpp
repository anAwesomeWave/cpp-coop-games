#include <SFML/Graphics.hpp>
#include "player.h"
#include "settings.h"

Player::Player(float X, float Y, sf::Color color, int rad, int speed) {
    x = X; 
    y = Y; 
    dir = -1;
    radius = rad;
    this->speed = speed;
    circle.setFillColor(color);
    circle.setOrigin({2, 2});
    circle.setRadius(radius);
    circle.setPosition({x, y});
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(circle);
}

void Player::setDir(int n) {

    dir = n % 4; // 0 1 2 3
}

int Player::getDir() const {
    return dir;
}

float Player::getX() const {
    return x;
}
float Player::getY() const {
    return y;
}

void Player::move() {
    switch (dir) {
        case -1:
            return;
        case 0: //left
            x -= speed;
            break;
        case 1:// up
            y -= speed;
            break;
        case 2: // right
            x += speed;
            break;
        case 3:// down
            y += speed;
            break;
    }
    if (x + radius <= 0)
        x = SCR_WIDTH;
    if (x - radius >= SCR_WIDTH)
        x = 0;
    if (y <= 0)
        y = SCR_HEIGHT - radius;
    if (y >= SCR_HEIGHT)
        y = 0;
    circle.setPosition({x, y});
}

int Player::getRadius() const {
    return radius;
}

void Player::setSpeed(int speed) {
    this->speed = speed;
}

int Player::getSpeed() const {
    return speed;
}
