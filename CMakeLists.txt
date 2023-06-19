cmake_minimum_required(VERSION 3.24)
project(Kasyno)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kasyno main.cpp method/BlackJack.cpp headers/BlackJack.h method/Player.cpp headers/Player.h method/Roulette.cpp headers/Roulette.h)
