cmake_minimum_required(VERSION 3.21)

project(BaseCom)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

set(BC_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)