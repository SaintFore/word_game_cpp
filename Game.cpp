#include "Game.h"
#include "Monster.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

Game::Game(Player pPlayer) : player(pPlayer) {}

void Game::start() {
    // 可以在这里初始化怪物
    monsters.push_back(std::make_unique<Orc>("兽人战士", 100, 5));
    monsters.push_back(std::make_unique<Goblin>("哥布林斥候", 30, 2));
    monsters.push_back(std::make_unique<Goblin>("哥布林斥候", 30, 2));

    while (true) {
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
    disAllMonsters(monsters);
    player.disStatus();
    player.attack(monsters);
    removeMonster(monsters);
}

void Game::monstersAction() {
    std::cout << "\n--- 怪物回合 ---" << std::endl;
    for (const auto &monster_ptr : monsters) {
        monster_ptr->attack(player);
    }
}

void Game::disAllMonsters(
    const std::vector<std::unique_ptr<Monster>> &monsters) {
    for (int i = 0; i < monsters.size(); i++) {
        std::cout << i << " ";
        monsters[i].get()->disStatus();
    }
}

void Game::removeMonster(std::vector<std::unique_ptr<Monster>> &monsters) {
    monsters.erase(std::remove_if(monsters.begin(), monsters.end(),
                                  [](const std::unique_ptr<Monster> &m) {
                                      return !m->isAlive();
                                  }),
                   monsters.end());
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
