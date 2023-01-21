//
// Created by Omer Bahat on 12/01/2023.
//

#include "Healer.h"
const std::string HEALER_TYPE = "Healer";

void Healer::heal(int healBy) {
    Player::heal(HEALER_MULTIPLE_HEALING_FACTOR*healBy);
}



void Healer::useManaCard() {
    this->heal(MANA_CARD_HEAL_AMOUNT);
}

Healer::Healer(const std::string &name) : Player(name, HEALER_TYPE) {}
std::ostream &operator<<(std::ostream &os, const Healer &player) {
    return os<<(Player)player;
}