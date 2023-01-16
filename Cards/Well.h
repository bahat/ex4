//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_WELLCARD_H
#define EX4_WELLCARD_H
#include "Card.h"

class Well: public Card{
    const std::string NINJA_TYPE = "Ninja";
public:
    void playCard(Player &player) const override;
    explicit Well();
};
static const std::string CARD_NAME = "Well";

#endif //EX4_WELLCARD_H
