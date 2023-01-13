//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include "Card.h"

class Dragon : public BattleCard{
    const std::string DRAGON_NAME = "Dragon";
    const int DRAGON_FORCE = 25;
    const int DRAGON_DAMAGE = -1;
    const int DRAGON_LOOT = 1000;
public:
    Dragon();
};


#endif //EX4_DRAGON_H
