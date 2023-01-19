//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H
#include "Card.h"

class BattleCard :public Card{
protected:
    const int m_force;
    const int m_damage;
    const int m_loot;
    BattleCard(const std::string &name, const int mForce, const int mDamage, const int mLoot);
    void lostTo(Player &player);

public:
    virtual void playCard(Player &player) override;
    void monsterPrinting(std::ostream &os) const override;
    int getForce() const;
    int getDamage() const;
    int getLoot() const;
    std::string getType() const;
};


#endif //EX4_BATTLECARD_H
