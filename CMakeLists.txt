cmake_minimum_required(VERSION 3.10)

project(UrlShortener)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(UrlShortener
    example/main.cpp
    UrlShortener/UrlShortener.cpp
    tree/tree.cpp
)

target_include_directories(UrlShortener PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/UrlShortener
    ${CMAKE_CURRENT_SOURCE_DIR}/tree
)