//
// Created by Omer Bahat on 12/01/2023.
//

#include "Well.h"

void WellCard::playCard(Player &player) const {
    player.useWellCard();
    printWellMessage(player.getType()==NINJA_TYPE);
}

WellCard::WellCard() : Card(CARD_NAME) {}
