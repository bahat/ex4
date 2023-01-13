//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_WELLCARD_H
#define EX4_WELLCARD_H
#include "Card.h"

class WellCard: public Card{
    const std::string CARD_NAME = "Well";
    const std::string NINJA_TYPE = "Ninja";
public:
    void playCard(Player &player) const override;
    explicit WellCard();
};


#endif //EX4_WELLCARD_H
