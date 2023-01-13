//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_NINJA_H
#define EX4_NINJA_H
#include "Player.h"

class Ninja : public Player{
const std::string NINJA_TYPE = "Ninja";
const int NINJA_COIN_FACTOR = 2;
public:
    explicit Ninja(const std::string &name);
    void addCoins(int toAdd) override;

    std::ostream &printInfo(std::ostream &os) override;

    std::string getType() override;
    void useWellCard() override;
};


#endif //EX4_NINJA_H
