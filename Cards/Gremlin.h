//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include "BattleCard.h"

class Gremlin: public BattleCard{
    static const int GREMLIN_FORCE = 5;
    static const int GREMLIN_DAMAGE = 10;
    static const int GREMLIN_LOOT = 2;
public:
    Gremlin();


};


#endif //EX4_GREMLIN_H
