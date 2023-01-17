//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H
#include "Card.h"

class Mana : public Card {
public:
    void playCard(Player &player) override;
    explicit Mana();
};


#endif //EX4_MANA_H
