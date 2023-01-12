//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H
#include "../Mtmchkin.h"

class Card {

public:
    virtual void playCard(Mtmchkin&) const=0;
};


#endif //EX4_CARD_H
