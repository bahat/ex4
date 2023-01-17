//
// Created by Omer Bahat on 12/01/2023.
//

#include "Treasure.h"


void Treasure::playCard(Player &currentPlayer) {
    currentPlayer.addCoins(TREASURE_DEFAULT_VALUE);
    printTreasureMessage();
}

Treasure::Treasure() : Card("Treasure") {}
