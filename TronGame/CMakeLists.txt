cmake_minimum_required(VERSION 3.5)

project(TronGame)

file(COPY tronData DESTINATION ${CMAKE_BINARY_DIR})
file(COPY tronData DESTINATION ${CMAKE_BINARY_DIR}/TronGame)

enable_testing()

add_library(
        Tron_lib
        STATIC
        game.cpp
        player.cpp
)

add_executable(Tron
        main.cpp
)

target_link_libraries(
        Tron
        PRIVATE
        Tron_lib
        sfml-graphics
        sfml-window
        sfml-system
        sfml-network
)

# add_executable(
#         ctest
#         tests.cpp
# )

# target_link_libraries(ctest 
#         PUBLIC
#         doctest
#         Tron_lib
#         sfml-graphics
#         sfml-window
#         sfml-system
#         sfml-network
# )

# cmake_minimum_required(VERSION 3.5)


# project(TicTacToe)
