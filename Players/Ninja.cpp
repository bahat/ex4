//
// Created by Omer Bahat on 12/01/2023.
//

#include "Ninja.h"
const std::string NINJA_TYPE = "Ninja";
const int NINJA_COIN_FACTOR = 2;

void Ninja::useWellCard() {

}

void Ninja::addCoins(int toAdd){
    Player::addCoins(NINJA_COIN_FACTOR*toAdd);
}


Ninja::Ninja(const std::string &name) : Player(name, NINJA_TYPE) {}

std::ostream &operator<<(std::ostream &os, const Ninja &player) {
    return os<<(Player)player;
}

