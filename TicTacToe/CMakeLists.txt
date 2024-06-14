file(COPY data DESTINATION ${CMAKE_BINARY_DIR})
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

add_executable(
        ctest
        tests.cpp
)

target_link_libraries(
        ctest
        PUBLIC
        doctest
        TicTacToe_lib
        sfml-graphics
        sfml-window
        sfml-system
        sfml-network
)
