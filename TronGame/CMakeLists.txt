cmake_minimum_required(VERSION 3.5)


project(TronGame)

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

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