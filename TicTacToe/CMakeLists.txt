cmake_minimum_required(VERSION 3.5)


project(TicTacToe)

add_executable(TicTacToe
        main.cpp
        server.cpp
        client.cpp
)

target_link_libraries(
    TicTacToe
        PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    sfml-network
)