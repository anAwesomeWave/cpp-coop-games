cmake_minimum_required(VERSION 3.5)


project(TicTacToe)

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

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