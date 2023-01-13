//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_HEALER_H
#define EX4_HEALER_H
#include "Player.h"

class Healer: public Player{
const std::string HEALER_TYPE = "Healer";
const int MANA_CARD_HEAL_AMOUNT = 10;
const int HEALER_MULTIPLE_HEALING_FACTOR = 2;
public:
    explicit Healer(const std::string &name);

    void heal(int healBy) override;
    std::ostream& printInfo(std::ostream &os) override;
    std::string getType() override;
    void useManaCard() override;

    void lostTo(const std::string monsterName) override;
};


#endif //EX4_HEALER_H
