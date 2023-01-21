cmake_minimum_required(VERSION 3.23)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(Cards)
include_directories(Players)

add_executable(ex4
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/BattleCard.cpp
        Cards/BattleCard.h
        Cards/Card.cpp
        Cards/Card.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Gremlin.cpp
        Cards/Gremlin.h
        Cards/Mana.cpp
        Cards/Mana.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Well.cpp
        Cards/Well.h
        Cards/Witch.cpp
        Cards/Witch.h
        Players/Healer.cpp
        Players/Healer.h
        Players/Ninja.cpp
        Players/Ninja.h
        Players/Player.cpp
        Players/Player.h
        Players/Warrior.cpp
        Players/Warrior.h
        Mtmchkin.h
        Mtmchkin.cpp
        utilities.cpp
        utilities.h main.cpp)
