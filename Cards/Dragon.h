//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include "BattleCard.h"

class Dragon : public BattleCard{
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_DAMAGE = -1;
    static const int DRAGON_LOOT = 1000;
public:
    Dragon();
};


#endif //EX4_DRAGON_H
