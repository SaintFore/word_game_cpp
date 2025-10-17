#include "Game.h"
#include "Player.h"
#include <iostream>

int main() {
    std::cout << "Hello 地牢世界" << std::endl;

    // 创建玩家
    Player p1("merlin", 100, 15);

    // 创建并开始游戏
    Game game(p1);
    game.start();

    return 0;
}
