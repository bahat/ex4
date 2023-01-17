//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_MERCHANTCARD_H
#define EX4_MERCHANTCARD_H
#include "Card.h"

class Merchant: public Card {
    static const int BUY_NOTHING = 0;
    static const int BUY_HP = 1;
    static const int BUY_FORCE = 2;
    static const int HP_PRICE = 5;
    static const int FORCE_PRICE = 10;
    static const int NO_PURCHASE_PRICE = 0;
    static const int HEAL_AMOUNT = 1;
    static const int BUFF_AMOUNT = 1;
public:
    void playCard(Player &player) override;

    explicit Merchant();
};


#endif //EX4_MERCHANTCARD_H
