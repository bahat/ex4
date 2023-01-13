//
// Created by Omer Bahat on 12/01/2023.
//

#include "Mana.h"

void ManaCard::playCard(Player &player) const
{
    player.useManaCard();
    printManaMessage(player.getType()==HEALER_TYPE);
}

ManaCard::ManaCard() : Card(CARD_NAME) {}

