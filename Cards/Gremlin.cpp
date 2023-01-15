//
// Created by Omer Bahat on 12/01/2023.
//

#include "Gremlin.h"

Gremlin::Gremlin() : BattleCard("Gremlin", GREMLIN_FORCE, GREMLIN_DAMAGE, GREMLIN_LOOT) {}

void Gremlin::playCard(Player &player) const {
    BattleCard::playCard(player);
}

std::ostream &Gremlin::operator<<(std::ostream &os) {
    return BattleCard::operator<<(os);
}
