//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_NINJA_H
#define EX4_NINJA_H
#include "Player.h"
#include "utilities.h"
class Ninja : public Player{
public:
    explicit Ninja(const std::string &name);
    virtual void addCoins(int toAdd) override;


    virtual std::string getType() const override;
    virtual void useWellCard() override;
};
std::ostream& operator<<(std::ostream& os, const Ninja &player);


#endif //EX4_NINJA_H
