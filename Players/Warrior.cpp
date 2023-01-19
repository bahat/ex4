//
// Created by Omer Bahat on 12/01/2023.
//

#include "Warrior.h"

const std::string WARRIOR_TYPE = "Warrior";
void Warrior::useBarfightCard() {

}

std::string Warrior::getType() const {
    return WARRIOR_TYPE;
}

int Warrior::getAttackStrength() {
    return 2*m_force+m_level;
}

Warrior::Warrior(const std::string &name) : Player(name) {}

std::ostream &operator<<(std::ostream &os, const Warrior &player) {
    printPlayerDetails(os, player.getName(), WARRIOR_TYPE, player.getLevel(), player.getForce(), player.getHP(), player.getCoins());
    return os;
}

