cmake_minimum_required(VERSION 3.10.0)

project("Coop_Games" CXX)

enable_testing()
add_subdirectory(external/doctest)
add_subdirectory(TicTacToe)
add_subdirectory(TronGame)
add_executable(coop-games
    main.cpp
)

target_link_libraries(
    coop-games
    PUBLIC
    TicTacToe_lib
    Tron_lib
    sfml-graphics
    sfml-window
    sfml-system
    sfml-network
)
