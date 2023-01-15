//
// Created by Omer Bahat on 12/01/2023.
//

#include "Dragon.h"

Dragon::Dragon() : BattleCard("Dragon", DRAGON_FORCE, DRAGON_DAMAGE, DRAGON_LOOT){}

void Dragon::playCard(Player &player) const {
    BattleCard::playCard(player);
}

std::ostream &Dragon::operator<<(std::ostream &os) {
    return BattleCard::operator<<(os);
}
