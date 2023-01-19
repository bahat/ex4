//
// Created by Omer Bahat on 12/01/2023.
//

#include "Ninja.h"

void Ninja::useWellCard() {

}

void Ninja::addCoins(int toAdd){
    Player::addCoins(NINJA_COIN_FACTOR*toAdd);
}

std::string Ninja::getType() const {
    return NINJA_TYPE;
}


Ninja::Ninja(const std::string &name) : Player(name) {}

std::ostream &Ninja::operator<<(std::ostream &os) const{
    printPlayerDetails(os, m_name, NINJA_TYPE, m_level, m_force, m_HP, m_coins);
    return os;
}
