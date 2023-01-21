//
// Created by Omer Bahat on 12/01/2023.
//

#include "Warrior.h"

const std::string WARRIOR_TYPE = "Warrior";
void Warrior::useBarfightCard() {

}


int Warrior::getAttackStrength() {
    return 2*m_force+m_level;
}

Warrior::Warrior(const std::string &name) : Player(name, WARRIOR_TYPE) {}


std::ostream &operator<<(std::ostream &os, const Warrior &player) {
    return os<<(Player)player;
}
