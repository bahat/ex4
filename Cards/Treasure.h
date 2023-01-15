//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_TREASURECARD_H
#define EX4_TREASURECARD_H
#include "Card.h"

class TreasureCard : public Card {
     const int TREASURE_DEFAULT_VALUE = 10;

public:
    void playCard(Player &currentPlayer) const override;

    explicit TreasureCard();
};


#endif //EX4_TREASURECARD_H
