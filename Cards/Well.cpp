//
// Created by Omer Bahat on 12/01/2023.
//

#include "Well.h"

void Well::playCard(Player &player) {
    player.useWellCard();
    printWellMessage(player.getType()==NINJA_TYPE);
}

Well::Well() : Card(CARD_NAME) {}
