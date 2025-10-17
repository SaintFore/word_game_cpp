#include "Game.h"
#include "Monster.h"
#include <iostream>

Game::Game(Player pPlayer) : player(pPlayer) {}

void Game::start() {
    // 可以在这里初始化怪物
    monsters.push_back(std::make_unique<Orc>("兽人战士", 100, 5));
    monsters.push_back(std::make_unique<Goblin>("哥布林斥候", 30, 2));
    monsters.push_back(std::make_unique<Goblin>("哥布林斥候", 30, 2));

    while (true) {
        disAllMonsters(monsters);
        playerAction();
        if (isOver(monsters, player))
            break;
        monstersAction();
        if (isOver(monsters, player))
            break;
    }
}

void Game::playerAction() {
    std::cout << "\n--- 玩家回合 ---" << std::endl;
    player.disStatus();
    player.attack(monsters);
}

void Game::monstersAction() {
    std::cout << "\n--- 怪物回合 ---" << std::endl;
    disAllMonsters(monsters);
    for (const auto &monster_ptr : monsters) {
        monster_ptr->attack(player);
    }
}

void Game::disAllMonsters(
    const std::vector<std::unique_ptr<Monster>> &monsters) {
    for (const auto &monster_ptr : monsters) {
        monster_ptr->disStatus();
    }
}

bool Game::isOver(const std::vector<std::unique_ptr<Monster>> &monsters,
                  Player &player) {
    if (monsters.size() == 0) {
        std::cout << "你讨伐了全部怪物! " << std::endl;
        return true;
    } else if (player.getHp() <= 0) {
        std::cout << "人被杀，就会死! 结束了，一切!!" << std::endl;
        return true;
    } else {
        return false;
    }
}
