cmake_minimum_required(VERSION 3.31)

project(dsa)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

set(SRC_DIR "src/dsa")

add_library(
    graph SHARED
    ${SRC_DIR}/graph.cc
)

add_library(
    trie SHARED
    ${SRC_DIR}/trie.cc
)

add_subdirectory(tests)
