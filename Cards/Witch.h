//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H
#include "BattleCard.h"

class Witch:public BattleCard {

static const int WITCH_FORCE = 11;
static const int WITCH_DAMAGE = 10;
static const int WITCH_LOOT = 2;
public:
    Witch();
};
static const std::string WITCH_NAME = "Witch";
#endif //EX4_WITCH_H
