//
// Created by Omer Bahat on 12/01/2023.
//

#include "Mana.h"

void ManaCard::playCard(Player &player) const
{
    player.useManaCard();
    printManaMessage(player.getType()=="Healer");
}

ManaCard::ManaCard() : Card("Mana") {}

