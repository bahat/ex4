//
// Created by Omer Bahat on 12/01/2023.
//

#include "Healer.h"

void Healer::heal(int healBy) {
    Player::heal(HEALER_MULTIPLE_HEALING_FACTOR*healBy);
}


std::string Healer::getType() const
{
    return HEALER_TYPE;
}

void Healer::useManaCard() {
    this->heal(MANA_CARD_HEAL_AMOUNT);
}

Healer::Healer(const std::string &name) : Player(name) {}

std::ostream &Healer::operator<<(std::ostream &os) const {
    printPlayerDetails(os, m_name, HEALER_TYPE, m_level, m_force, m_HP, m_coins);
    return os;
}


