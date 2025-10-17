#pragma once

#include "Monster.h"
#include "Player.h"
#include <memory>
#include <vector>

class Game {
  private:
    Player player;
    std::vector<std::unique_ptr<Monster>> monsters;

    void playerAction();
    void monstersAction();
    bool isOver(const std::vector<std::unique_ptr<Monster>> &monsters,
                Player &player);

  public:
    Game(Player pPlayer);
    void start();
    void disAllMonsters(const std::vector<std::unique_ptr<Monster>> &monsters);
};
