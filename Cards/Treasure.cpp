//
// Created by Omer Bahat on 12/01/2023.
//

#include "Treasure.h"


void TreasureCard::playCard(Player &currentPlayer) const {
    currentPlayer.addCoins(TREASURE_DEFAULT_VALUE);
    printTreasureMessage();
}

TreasureCard::TreasureCard() : Card(CARD_NAME) {}
