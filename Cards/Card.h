//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H
#include "Player.h"
#include "utilities.h"
class Card {


protected:
    std::string m_cardName;
    Card(std::string name): m_cardName(name){};
public:
    virtual void playCard(Player &player)=0;
    virtual std::ostream& operator<<(std::ostream& os);
};


#endif //EX4_CARD_H
