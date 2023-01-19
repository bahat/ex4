//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H
#include "Card.h"
class Barfight: public Card {


public:
    explicit Barfight();
//    void playCard(Player &player) const override;
    virtual void playCard(Player &player) override;
};
#endif //EX4_BARFIGHT_H
