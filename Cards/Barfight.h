//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_BARFIGHTCARD_H
#define EX4_BARFIGHTCARD_H
#include "Card.h"

class BarfightCard: public Card {

    const std::string WARRIOR_TYPE = "Warrior";
    const std::string CARD_NAME = "Barfight";

public:
    explicit BarfightCard();
    void playCard(Player &player) const override;

};


#endif //EX4_BARFIGHTCARD_H
