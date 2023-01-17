//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H
#include "Player.h"
#include "utilities.h"
class Warrior : public Player{
const std::string WARRIOR_TYPE = "Warrior";
public:
    virtual int getAttackStrength() override;

    explicit Warrior(const std::string &name);

    virtual std::ostream &printInfo(std::ostream &os) override;

    std::ostream &operator<<(std::ostream &os) override;

    virtual std::string getType() const override;
    virtual void useBarfightCard() override;
};


#endif //EX4_WARRIOR_H
