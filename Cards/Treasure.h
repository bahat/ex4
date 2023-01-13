//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_TREASURECARD_H
#define EX4_TREASURECARD_H
#include "Card.h"

class TreasureCard : public Card {
     const int TREASURE_DEFAULT_VALUE = 10;
     const std::string TREASURE_NAME = "Treasure";

public:
    void printCard() const override;
    void playCard(Player &currentPlayer) const override;
};


#endif //EX4_TREASURECARD_H
