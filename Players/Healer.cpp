//
// Created by Omer Bahat on 12/01/2023.
//

#include "Healer.h"
const std::string HEALER_TYPE = "Healer";

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

std::ostream &operator<<(std::ostream &os, const Healer &player) {
    printPlayerDetails(os, player.getName(), HEALER_TYPE, player.getLevel(), player.getForce(), player.getHP(), player.getCoins());
    return os;
}