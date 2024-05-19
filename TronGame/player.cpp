#include <SFML/Graphics.hpp>
#include "playerClass.hpp"
#include "settings.hpp"

Player::Player(float X, float Y, sf::Color color) {
    x = X; y = Y; dir = -1;
    circle.setFillColor(color);
    circle.setOrigin({2, 2});
    circle.setRadius(radius);
    circle.setPosition({x, y});
}

void Player::move() {
    if(dir == 0){ //left
        x -= speed;
    }
    if(dir == 1){ // up
        y -= speed;
    }
    if(dir == 2){ // right
        x += speed;
    }
    if(dir == 3){ // down
        y += speed;
    }
    if(x + radius<= 0)
        x = SCR_WIDTH;
    if(x - radius>= SCR_WIDTH)
        x = 0;
    if(y <= 0)
        y = SCR_HEIGHT;
    if(y - radius >= SCR_HEIGHT)
        y = 0;
    circle.setPosition({x, y});
}