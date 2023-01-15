//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H
#include "Card.h"

class Witch:public BattleCard {
const std::string WITCH_NAME = "Witch";
const int WITCH_FORCE = 11;
const int WITCH_DAMAGE = 10;
const int WITCH_LOOT = 2;
public:
    Witch();

    void playCard(Player &player) const override;

    std::ostream &operator<<(std::ostream &os) override;
};
#endif //EX4_WITCH_H
