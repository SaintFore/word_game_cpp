#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Character.h"

class Monster;
class Player : public Character {
  public:
    Player(std::string pName, int pHp, int pAttackPower);

    void attack(std::vector<std::unique_ptr<Monster>> &monsters);
    int chooseMonster();
};
