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
    virtual void heal(int healBy) override;
    virtual std::ostream& printInfo(std::ostream &os) override;
    virtual std::string getType() const override;
    virtual void useManaCard() override;
};


#endif //EX4_HEALER_H
