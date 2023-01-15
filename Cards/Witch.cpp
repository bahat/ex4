//
// Created by Omer Bahat on 12/01/2023.
//

#include "Witch.h"

Witch::Witch() : BattleCard(WITCH_NAME, WITCH_FORCE, WITCH_DAMAGE, WITCH_LOOT) {}

std::ostream &Witch::operator<<(std::ostream &os) {
    return BattleCard::operator<<(os);
}

void Witch::playCard(Player &player) const {
    BattleCard::playCard(player);
}
