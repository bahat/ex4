//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H
#include "Player.h"

class Warrior : public Player{
const std::string WARRIOR_TYPE = "Warrior";
public:
    int getAttackStrength() override;

    explicit Warrior(const std::string &name);

    std::ostream &printInfo(std::ostream &os) override;

    std::string getType() const override;
    void useBarfightCard() override;
};


#endif //EX4_WARRIOR_H
