//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard: public Card{
protected:
    const int m_force;
    const int m_damage;
    const int m_loot;
    BattleCard(const std::string &name, const int mForce, const int mDamage, const int mLoot);

public:
    virtual void playCard(Player &player) const override;
    virtual std::ostream& operator<<(std::ostream& os) override;
    int getForce() const;
    int getDamage() const;
    int getLoot() const;
    std::string getType() const;
};


#endif //EX4_BATTLECARD_H
