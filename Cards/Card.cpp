//
// Created by Omer Bahat on 12/01/2023.
//

#include "Card.h"

std::ostream &Card::operator<<(std::ostream &os) {
    printCardDetails(os, m_cardName);
    printEndOfCardDetails(os);
    return os;
}

