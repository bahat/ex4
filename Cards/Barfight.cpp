//
// Created by Omer Bahat on 12/01/2023.
//

#include "Barfight.h"


Barfight::Barfight() : Card("Barfight") {}

void Barfight::playCard(Player &player) {
    player.useBarfightCard();
    printBarfightMessage(player.getType()=="Warrior");
}

std::ostream &Barfight::operator<<(std::ostream &os) {
    return Card::operator<<(os);
}



