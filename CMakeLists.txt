cmake_minimum_required(VERSION 3.15)
project(CustomString VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS "Build tests" ON)
option(STRING_ITERATORS "Enable iterators" ON)

add_library(cppstring 
    src/cppstring.cpp
)

# Указываем где искать заголовочные файлы
target_include_directories(cppstring 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Тесты
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()