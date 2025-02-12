cmake_minimum_required(VERSION 3.11)

project(FitnessApp
  LANGUAGES CXX
  VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PROJECT_HOMEPAGE_URL "https://github.com/PrimeStrength/FitnessApp")

add_subdirectory(software)
add_subdirectory(packaging)
