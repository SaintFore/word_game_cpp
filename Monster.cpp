#include "Monster.h"
#include "Player.h" // 需要 Player 的完整定义
#include <iostream>

// --- Monster 基类实现 ---
// 构造函数，将参数传递给 Character 的构造函数
Monster::Monster(std::string pName, int pHp, int pAttack)
    : Character(pName, pHp, pAttack) {}

// Monster 不再需要实现 takeDamage, getHp 等方法，因为 Character 已经做好了

// --- Goblin 实现 ---
Goblin::Goblin(std::string pName, int pHp, int pAttack)
    : Monster(pName, pHp, pAttack) {
    std::cout << "一只哥布林已被部署进入战场!" << std::endl;
}

void Goblin::attack(Player &target) {
    std::cout << "哥布林对 " << target.getName() << " 发起了阴险的偷袭!"
              << std::endl;
    target.takeDamage(attackPower);
}

// --- Orc 实现 ---
Orc::Orc(std::string pName, int pHp, int pAttack)
    : Monster(pName, pHp, pAttack) { // 调用 Monster 的构造函数
    std::cout << "一只兽人已被部署进入战场!" << std::endl;
}

void Orc::attack(Player &target) {
    std::cout << "兽人对 " << target.getName() << " 发出了咆哮!" << std::endl;
    target.takeDamage(attackPower);
}
