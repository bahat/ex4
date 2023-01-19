//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H
#include "Player.h"
#include "utilities.h"
class Warrior : public Player{
public:
    virtual int getAttackStrength() override;

    explicit Warrior(const std::string &name);


    virtual std::string getType() const override;
    virtual void useBarfightCard() override;
};

std::ostream &operator<<(std::ostream &os, const Warrior &player);

#endif //EX4_WARRIOR_H
