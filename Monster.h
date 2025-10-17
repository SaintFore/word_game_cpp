#pragma once

#include "Character.h"
#include <string>

class Player;

class Monster : public Character {
  public:
    Monster(std::string pName, int pHp, int pAttackPower);
    virtual void attack(Player &player) = 0;
};

class Orc : public Monster {
  public:
    Orc(std::string pName, int pHp, int pAttackPower);
    void attack(Player &player) override;
};

class Goblin : public Monster {
  public:
    Goblin(std::string pName, int pHp, int pAttackPower);
    void attack(Player &player) override;
};
