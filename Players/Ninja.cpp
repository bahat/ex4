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

std::string Ninja::getType() const {
    return NINJA_TYPE;
}


Ninja::Ninja(const std::string &name) : Player(name) {}



std::ostream &operator<<(std::ostream &os, const Ninja &player) {
    printPlayerDetails(os, player.getName(), NINJA_TYPE, player.getLevel(), player.getForce(), player.getHP(), player.getCoins());
    return os;
}
