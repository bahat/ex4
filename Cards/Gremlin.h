//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include "Card.h"

class Gremlin: public BattleCard{
    const std::string GREMLIN_NAME = "Gremlin";
    const int GREMLIN_FORCE = 5;
    const int GREMLIN_DAMAGE = 10;
    const int GREMLIN_LOOT = 2;
public:
    Gremlin();
};


#endif //EX4_GREMLIN_H
