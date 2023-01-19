//
// Created by Omer Bahat on 12/01/2023.
//

#include "Card.h"

std::ostream &operator<<(std::ostream &os, Card &card) {
    printCardDetails(os, card.getName());
    printEndOfCardDetails(os);
    return os;
}

std::string Card::getName() {
    return m_cardName;
}
