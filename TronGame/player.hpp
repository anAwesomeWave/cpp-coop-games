#pragma once

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
    void draw(sf::RenderWindow& window);
    void setDir(int n);
    int getDir();
    float getX();
    float getY();
};
