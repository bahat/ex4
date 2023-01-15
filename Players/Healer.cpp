//
// Created by Omer Bahat on 12/01/2023.
//

#include "Healer.h"

void Healer::heal(int healBy) {
    Player::heal(HEALER_MULTIPLE_HEALING_FACTOR*healBy);
}

std::ostream& Healer::printInfo(std::ostream &os) {
    printPlayerDetails(os, m_name, HEALER_TYPE, m_level, m_force, m_HP, m_coins);
    return os;
}

std::string Healer::getType() const
{
    return HEALER_TYPE;
}

void Healer::useManaCard() {
    this->heal(MANA_CARD_HEAL_AMOUNT);
}

Healer::Healer(const std::string &name) : Player(name) {}


