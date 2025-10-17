#include "Player.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>
#include <memory>
#include <vector>

Player::Player(std::string pName, int pHp, int pAttackPower)
    : Character(pName, pHp, pAttackPower) {}

void Player::attack(std::vector<std::unique_ptr<Monster>> &monsters) {
    int number = chooseMonster();
    if (number >= 0 && number < monsters.size()) {
        Monster *monster = monsters[number].get();
        monster->takeDamage(attackPower);
        std::cout << "[" + name + "]攻击了[" + monster->getName() + "]"
                  << std::endl;
    } else {
        std::cout << "无效目标! " << std::endl;
    }
}

int Player::chooseMonster() {
    int number;
    std::cout << "请输入你想要攻击的怪物: ";
    std::cin >> number;
    return number;
}
