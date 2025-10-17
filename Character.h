#pragma once

#include <string>
class Character {
  protected:
    std::string name;
    int hp;
    int attackPower;

  public:
    Character(std::string pName, int pHp, int pAttackPower);
    std::string getName();
    int getHp();
    int getAttackPower();

    void takeDamage(int damage);
    bool isAlive();
    void disStatus();
};
