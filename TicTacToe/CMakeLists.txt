cmake_minimum_required(VERSION 3.5)


project(TicTacToe)

# file(COPY data DESTINATION ${CMAKE_BINARY_DIR})
file(COPY data DESTINATION ${CMAKE_BINARY_DIR}/TicTacToe)

add_library(
        TicTacToe_lib
        STATIC
        server.cpp
        client.cpp
)
add_executable(TicTacToe
        main.cpp

)

target_link_libraries(
    TicTacToe
        PRIVATE
    TicTacToe_lib
    sfml-graphics
    sfml-window
    sfml-system
    sfml-network
)

enable_testing()
#add_custom_target(ctest tests.cpp)
add_executable(
        ctest
        tests.cpp
)

target_link_libraries(ctest PUBLIC doctest TicTacToe_lib     sfml-graphics
        sfml-window
        sfml-system
        sfml-network)
#target_link_libraries(ctest PUBLIC TicTacToe)
#add_dependencies(ctest TicTacToe_lib)
#target_link_libraries(my_tests PUBLIC doctest default)
#add_test(NAME my_tests COMMAND my_tests --force-colors -d)
