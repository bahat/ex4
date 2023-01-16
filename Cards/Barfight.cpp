//
// Created by Omer Bahat on 12/01/2023.
//

#include "Barfight.h"


Barfight::Barfight() : Card("Warrior") {}

void Barfight::playCard(Player &player) const {
    player.useBarfightCard();
    printBarfightMessage(player.getType()=="Warrior");
}



