#include "server.h"
#include <algorithm>
#include <doctest.h>
#include <vector>


TEST_CASE("check tests")
{
//    template <typename T>
//    using v<T> = std::vector<T>;
    CHECK(1 == 1);

//    v<v<int>> emptyMap;
}

TEST_CASE("CHECK SERVER isWin")
{
    std::vector<std::vector<int>> map(3, std::vector<int>(3));
    CHECK(isWin(map) == false);  //empty
    // CHECK(isWin(emptyMap) == true); // should fail
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

TEST_CASE("CHECK SERVER isWindoesn't process client moves")
{
    std::vector<std::vector<int>> map(3, std::vector<int>(3));
    CHECK(isWin(map) == false);  //empty
    // CHECK(isWin(emptyMap) == true); // should fail
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
