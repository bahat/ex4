//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_HEALER_H
#define EX4_HEALER_H
#include "Player.h"
#include "utilities.h"

class Healer: public Player{
const int MANA_CARD_HEAL_AMOUNT = 10;
const int HEALER_MULTIPLE_HEALING_FACTOR = 2;
public:
    explicit Healer(const std::string &name);
    virtual void heal(int healBy) override;
    virtual void useManaCard() override;
};
std::ostream &operator<<(std::ostream &os, const Healer &player);

#endif //EX4_HEALER_H
