#include "Character.h"
#include <iostream>

Character::Character(std::string pName, int pHp, int pAttackPower)
    : name(pName), hp(pHp), attackPower(pAttackPower) {}

void Character::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
}

std::string Character::getName() { return name; }
int Character::getHp() { return hp; }
int Character::getAttackPower() { return attackPower; }

bool Character::isAlive() { return hp > 0; }
void Character::disStatus() {
    std::cout << std::string("[") + name + std::string("],生命[") << hp
              << std::string("],攻击[") << attackPower << "]" << std::endl;
}
