//
// Created by Omer Bahat on 12/01/2023.
//

#include "Warrior.h"

void Warrior::useBarfightCard() {

}

std::string Warrior::getType() {
    return WARRIOR_TYPE;
}

int Warrior::getAttackStrength() {
    return 2*m_force+m_level;
}

Warrior::Warrior(const std::string &name) : Player(name) {}

std::ostream &Warrior::printInfo(std::ostream &os) {
    printPlayerDetails(os, m_name, WARRIOR_TYPE, m_level, m_force, m_HP, m_coins);
    return os;
}
