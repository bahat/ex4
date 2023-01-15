//
// Created by Omer Bahat on 12/01/2023.
//

#include "Barfight.h"

void BarfightCard::playCard(Player &player) const {
    player.useBarfightCard();
    printBarfightMessage(player.getType()=="Warrior");
}
BarfightCard::BarfightCard() : Card("Warrior") {}



