//
// Created by Omer Bahat on 12/01/2023.
//

#include "Barfight.h"

void Barfight::playCard(Player &player) const {
    player.useBarfightCard();
    printBarfightMessage(player.getType()=="Warrior");
}
Barfight::Barfight() : Card("Warrior") {}

std::ostream &Barfight::operator<<(std::ostream &os) {
    return Card::operator<<(os);
}



