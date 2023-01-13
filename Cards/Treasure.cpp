//
// Created by Omer Bahat on 12/01/2023.
//

#include "Treasure.h"

void TreasureCard::printCard() const {
    printCardDetails(std::cout, TREASURE_NAME);
    printTreasureMessage();
    printEndOfCardDetails(std::cout);
}

void TreasureCard::playCard(Player &currentPlayer) const {
    currentPlayer.
}
