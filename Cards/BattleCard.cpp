//
// Created by Omer Bahat on 12/01/2023.
//

#include "BattleCard.h"
const std::string DRAGON_NAME = "Dragon";
const std::string WITCH_NAME = "Witch";
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
void BattleCard::playCard(Player &player) {
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
        lostTo(player);
        printLossBattle(player.getName(), m_cardName);
    }
}

void BattleCard::monsterPrinting(std::ostream &os) const{
    printMonsterDetails(os, m_force, m_damage, m_loot, (m_cardName=="Dragon"));
}

void BattleCard::lostTo(Player &player){
    if(m_cardName==DRAGON_NAME)
    {
        player.killPlayer();
        return;
    }
    else if (m_cardName==WITCH_NAME)
    {

        player.deBuff(1);
    }
    player.damage(m_damage);
}
