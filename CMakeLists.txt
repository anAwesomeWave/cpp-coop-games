cmake_minimum_required(VERSION 3.10.0)

project("Coop_Games" CXX)


#list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
#add_library(default INTERFACE)
#target_compile_features(default INTERFACE cxx_std_20)

#include(cmake/CompilerWarnings.cmake)
#set_project_warnings(default)

# file(COPY TicTacToe/data DESTINATION ${CMAKE_BINARY_DIR})
enable_testing()
add_subdirectory(external/doctest)
add_subdirectory(TicTacToe)
add_subdirectory(TronGame)
add_executable(COOPGAMES
    main.cpp
)

target_link_libraries(
    COOPGAMES
    PUBLIC
    TicTacToe_lib
    Tron_lib
    sfml-graphics
    sfml-window
    sfml-system
    sfml-network
)
