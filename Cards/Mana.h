//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_MANACARD_H
#define EX4_MANACARD_H
#include "Card.h"

class ManaCard : public Card {
public:
    void playCard(Player &player) const override;
    explicit ManaCard();
};


#endif //EX4_MANACARD_H
