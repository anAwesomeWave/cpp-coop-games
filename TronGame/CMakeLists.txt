file(COPY tronData DESTINATION ${CMAKE_BINARY_DIR})
file(COPY tronData DESTINATION ${CMAKE_BINARY_DIR}/TronGame)


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

enable_testing()

add_executable(
        ctest-tron
        tests.cpp
)

target_link_libraries(
        ctest-tron
        PUBLIC
        doctest
        Tron_lib
        sfml-graphics
        sfml-window
        sfml-system
        sfml-network
)
