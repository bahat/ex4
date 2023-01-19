//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_NINJA_H
#define EX4_NINJA_H
#include "Player.h"
#include "utilities.h"
class Ninja : public Player{
const std::string NINJA_TYPE = "Ninja";
const int NINJA_COIN_FACTOR = 2;
public:
    explicit Ninja(const std::string &name);
    virtual void addCoins(int toAdd) override;

    std::ostream &operator<<(std::ostream &os) const;

    virtual std::string getType() const override;
    virtual void useWellCard() override;
};


#endif //EX4_NINJA_H
