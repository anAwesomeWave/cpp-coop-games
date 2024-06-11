#include <SFML/Graphics.hpp>
#include <algorithm>
#include <doctest.h>
#include <vector>

#include "game.h"
#include "player.hpp"


using std::vector;


TEST_CASE("endOfGame processing")
{
    vector<vector<int>> field(10, vector<int>(10));
    Player p1(0, 0, sf::Color::Green);
    Player p2(5, 5, sf::Color::Blue);

    field[0][0] = 1;
    field[5][5] = 2;
    CHECK(endOfGame(p1, p2, field) == 0); // изначальное состояние

    p2.setDir(2);

    CHECK(endOfGame(p1, p2, field) == 2); // сам в себя

    field[5][5] = 0;

    CHECK(endOfGame(p1, p2, field) == 0); // теперь клетка пустая
    
}


TEST_CASE("endOfGame error handling")
{
    // проверка того, как ведет себя функция, если координаты игроков совпадют
    vector<vector<int>> field(10, vector<int>(10));
    Player p1(0, 0, sf::Color::Green);
    Player p2(0, 0, sf::Color::Blue);

    CHECK(endOfGame(p1, p2, field) == 0); // изначальное состояние


    field[0][0] = 1;
    field[5][5] = 2;
    CHECK(endOfGame(p1, p2, field) != 0); // сам в себя

}
