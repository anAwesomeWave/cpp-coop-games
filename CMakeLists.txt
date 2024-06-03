cmake_minimum_required(VERSION 3.10.0)

project("Coop Games" CXX)


#list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
#add_library(default INTERFACE)
#target_compile_features(default INTERFACE cxx_std_20)

#include(cmake/CompilerWarnings.cmake)
#set_project_warnings(default)

enable_testing()
add_subdirectory(external/doctest)
add_subdirectory(TicTacToe)
