//
// Created by Omer Bahat on 12/01/2023.
//

#include "BattleCard.h"

//std::ostream &BattleCard::operator<<(std::ostream &os) {

//}

//void BattleCard::playCard(Player &player) const {

//
//}

int BattleCard::getForce() const {
    return m_force;
}

int BattleCard::getDamage() const {
    return m_damage;
}

int BattleCard::getLoot() const {
    return m_loot;
}

std::string BattleCard::getType() const {
    return m_cardName;
}

BattleCard::BattleCard(const std::string &name, const int mForce, const int mDamage, const int mLoot) : Card(name), m_force(mForce), m_damage(mDamage), m_loot(mLoot)
{
}
void BattleCard::playCard(Player &player) const {
    if(player.getAttackStrength()>=this->m_force)
    {
        //win
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_cardName);
    }
    else
    {
        //loss
        player.lostTo(this);
        printLossBattle(player.getName(), m_cardName);
    }
}

std::ostream &BattleCard::operator<<(std::ostream &os) {
    printCardDetails(os, m_cardName);
    printMonsterDetails(os, m_force, m_damage, m_loot, (m_cardName=="Dragon"));
    printEndOfCardDetails(os);
    return os;
}


