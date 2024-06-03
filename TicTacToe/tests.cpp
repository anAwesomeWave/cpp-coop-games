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

TEST_CASE("CHECK SERVER isWIN")
{
    std::vector<std::vector<int>> emptyMap(3, std::vector<int>(3));
    CHECK(isWin(emptyMap) == false);
    CHECK(isWin(emptyMap) == true); // should fail
}