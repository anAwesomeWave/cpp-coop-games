#include "server.h"
#include "client.h"
#include <algorithm>
#include <doctest.h>
#include <vector>


TEST_CASE("CHECK SERVER isWin")
{
    std::vector<std::vector<int>> map(3, std::vector<int>(3));
    CHECK(isWin(map) == false);  //empty
    for (int i = 0; i < 3; i++) {
        map[i][i] = 1;
    }
    CHECK(isWin(map) == true);
    map[0][0] = 0;
    CHECK(isWin(map) == false);
    map[0][2] = 1;
    map[2][0] = 1;
    CHECK(isWin(map) == true);
}

TEST_CASE("CHECK SERVER isWin doesn't process client moves")
{
    std::vector<std::vector<int>> map(3, std::vector<int>(3));
    CHECK(isWin(map) == false);  //empty
    for (int i = 0; i < 3; i++) {
        map[i][i] = 2;
    }
    CHECK(isWin(map) == false);
    map[0][0] = 0;
    CHECK(isWin(map) == false);
    map[0][2] = 2;
    map[2][0] = 2;
    CHECK(isWin(map) == false);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            map[i][j] = 2;
        }
    }
    CHECK(isWin(map) == false);
}

TEST_CASE("CHECK SERVER processClick function") {
    std::vector<std::vector<int>> map(3, std::vector<int>(3));
    CHECK(processClick(1, 1, 1, 1, 0, map) == 0);
    CHECK(map[1][1] == 1);
    CHECK(processClick(5, 4, 6, 2, 1, map) == 0);
    CHECK(map[2][0] == 2);
}

TEST_CASE("CHECK SERVER processClick invalid data processing") {
    std::vector<std::vector<int>> map(3, std::vector<int>(3));

    // negative coords
    CHECK(processClick(-1, 1, 1, 1, 0, map) == 1);
    CHECK(map[1][1] != 1);

    CHECK(processClick(5, -1, 6, 2, 1, map) == 1);
    CHECK(map[2][0] != 2);

    // occupied cell
    map[1][1] = 1;
    CHECK(processClick(15, 16, 10, 15, 1, map) == 1);

}

TEST_CASE("CHECK SERVER setUpWindow function") {
    sf::RenderWindow window;
    CHECK(setUpWindow(window, 120, 120, "test") == 0);
    CHECK(window.getSize().x == 120);
    CHECK(window.getSize().y == 120);
}

TEST_CASE("CHECK SERVER setUpWindow invalid size function") {
    sf::RenderWindow window;
    
    // check negative
    CHECK(setUpWindow(window, -10, 0, "test") == 1);
    CHECK(window.getSize().x == 0);
    CHECK(window.getSize().y == 0);

    //check not divisivle
    CHECK(setUpWindow(window, 120, 119, "test") == 1);
    CHECK(window.getSize().x == 0);
    CHECK(window.getSize().y == 0);
}

TEST_CASE("CHECK CLIENT isCWin")
{
    std::vector<std::vector<int>> map(3, std::vector<int>(3));
    CHECK(isCWin(map) == false);
    for (int i = 0; i < 3; i++) {
        map[i][0] = 2;
    }
    CHECK(isCWin(map) == true);
    map[0][0] = 0;
    CHECK(isCWin(map) == false);
    for (int i = 0; i < 3; i++) {
        map[i][0] = 0;
        map[0][i] = 2;
    }
    CHECK(isCWin(map) == true);
}


TEST_CASE("CHECK CLIENT clientDrawCircle")
{
    std::vector<std::pair<int, int>> balls;
    clientDrawCircle(300, 210, balls);
    CHECK(balls[0].first == 250);
    CHECK(balls[0].second == 250);
    clientDrawCircle(0, 0, balls);
    CHECK(balls[1].first != 250);
    CHECK(balls[1].second != 250);
    clientDrawCircle(500, 0, balls);
    CHECK(balls[2].first == 450);
    CHECK(balls[2].second == 50);
}

TEST_CASE("CHECK CLIENT clientDrawCircle wrong coordinates")
{
    std::vector<std::pair<int, int>> balls;
    CHECK(clientDrawCircle(-10, 0, balls) == false);
    CHECK(size(balls) == 0);
	CHECK(clientDrawCircle(10, 10, balls) == true);
	CHECK(balls[0].first == 50);
    CHECK(balls[0].second == 50);
}

TEST_CASE("CHECK CLIENT clientDrawSquare")
{
    std::vector<std::vector<int>> map(3, std::vector<int>(3));
    std::vector<std::pair<int, int>> squares;
    int turn = 0;
    int x = -1;
    int y = -1;
    clientDrawSquare(300, 210, squares, map, turn, x, y);
    CHECK((squares[0].first) == 250);
    CHECK((squares[0].second) == 250);
    clientDrawSquare(0, 0, squares, map, turn, x, y);
    CHECK((squares[1].first) != 250);
    CHECK((squares[1].second) != 250);
    clientDrawSquare(500, 0, squares, map, turn, x, y);
    CHECK((squares[2].first) == 450);
    CHECK((squares[2].second) == 50);
}

TEST_CASE("CHECK CLIENT clientDrawSquare draw in used cell")
{
    std::vector<std::vector<int>> map(3, std::vector<int>(3));
    std::vector<std::pair<int, int>> squares;
    int turn = 0;
    int send_x = -1;
    int send_y = -1;
    int x = 300;
    int y = 210;
    if (clientDrawSquare(x, y, squares, map, turn, send_x, send_y) == true) {
        map[x / 200][y / 200] = 2;
    }
    CHECK(squares[0].first == 250);
    CHECK(clientDrawSquare(280, 240, squares, map, turn, x, y) == false);
    CHECK(clientDrawSquare(420, 240, squares, map, turn, x, y) == true);
}
