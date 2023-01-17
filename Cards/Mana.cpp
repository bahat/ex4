//
// Created by Omer Bahat on 12/01/2023.
//

#include "Mana.h"

void Mana::playCard(Player &player)
{
    player.useManaCard();
    printManaMessage(player.getType()=="Healer");
}

Mana::Mana() : Card("Mana") {}

