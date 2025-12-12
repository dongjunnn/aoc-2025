cmake_minimum_required(VERSION 3.16)
project(advent_of_code CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

function(add_aoc_day year day)
    set(target "aoc_${year}_day${day}")
    add_executable(${target} "src/${year}/day${day}.cpp")
endfunction()

add_aoc_day(2025 01)
add_aoc_day(2025 02)
add_aoc_day(2025 03)
add_aoc_day(2025 04)
add_aoc_day(2025 05)
add_aoc_day(2025 06)
add_aoc_day(2025 07)
