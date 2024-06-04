cmake_minimum_required(VERSION 3.5)

project(TronGame)

add_executable(TronGame
        main.cpp
        player.cpp
)

target_link_libraries(
        TronGame
        PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        sfml-network
)
