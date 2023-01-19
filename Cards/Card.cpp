//
// Created by Omer Bahat on 12/01/2023.
//

#include "Card.h"


std::string Card::getName() const {
    return m_cardName;
}

std::ostream &operator<<(std::ostream &os, const Card &card)
{
        printCardDetails(os, card.getName());
        card.monsterPrinting(os);
        printEndOfCardDetails(os);
        return os;
}
