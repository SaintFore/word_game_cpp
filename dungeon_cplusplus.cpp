#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Player;

// Monster
class Monster {
  private:
    std::string name;
    int hp;
    int attack;

  public:
    Monster(std::string pName, int pHp, int pAttack)
        : name(pName), hp(pHp), attack(pAttack) {}
    void disStatus() {
        std::cout << std::string("怪物[") + name + std::string("],生命[") << hp
                  << std::string("],攻击[") << attack << "]" << std::endl;
    }
    void takeDamage(int damage) { hp = hp - damage; }
    std::string getName() { return name; }
    int getHp() { return hp; }
    int getAttack() { return attack; }

    virtual void attackPlayer(Player &target) {}
};
// Player
class Player {
  private:
    std::string name;
    int hp;
    int attack;

  public:
    Player(std::string pName, int pHp, int pAttack)
        : name(pName), hp(pHp), attack(pAttack) {}

    int getHp() { return hp; }
    int getAttack() { return attack; }
    std::string getName() { return name; }
    void disStatus() {

        std::cout << std::string("玩家[") + name + "],生命[" << hp << "],攻击["
                  << attack << "]" << std::endl;
    }
    void takeDamage(int damage) { hp = hp - damage; }
    void goAttack(std::vector<std::unique_ptr<Monster>> &monsters) {
        int number = choeseMonster();
        if (number >= 0 && number < monsters.size()) {
            Monster *monster = monsters[number].get();
            monster->takeDamage(attack);
            std::cout << "[" + name + "]攻击了[" + monster->getName() + "]"
                      << std::endl;
        } else {
            std::cout << "无效目标! " << std::endl;
        }
    }
    int choeseMonster() {
        int number;
        std::cout << "请输入你想要攻击的怪物: ";
        std::cin >> number;
        return number;
    }
};

class Goblin : public Monster {
  public:
    Goblin(std::string pName, int pHp, int pAttack)
        : Monster(pName, pHp, pAttack) {
        std::cout << "一只哥布林已被部署进入战场! " << std::endl;
    }

    void attackPlayer(Player &target) override {
        std::cout << "哥布林发起了阴险的偷袭" << std::endl;
        target.takeDamage(getAttack());
    }
};

class Orc : public Monster {
  public:
    Orc(std::string pName, int pHp, int pAttack)
        : Monster(pName, pHp, pAttack) {
        std::cout << "一只兽人已被部署进入战场! " << std::endl;
    }

    void attackPlayer(Player &target) override {
        std::cout << "兽人发出了咆哮! " << std::endl;
        target.takeDamage(getAttack());
    }
};

// Game
class Game {

  public:
    Player player;
    std::vector<std::unique_ptr<Monster>> monsters;
    Game(Player pPlayer) : player(pPlayer) {}
    // 析构函数，对象生命周期结束后调用
    // ~Game() {
    //     std::cout << "清扫战场中..." << std::endl;
    //     for (Monster *mptr : monsters) {
    //         delete mptr; // 释放创造的monster
    //     }
    // }
    void start() {
        while (true) {
            playerAction();
            monstersAction();

            // std::erase_if(monsters,[](Monster & m){
            //     return m.getHp() <= 0;
            // })
            if (isOver(monsters, player)) {
                break;
            }
        }
    }
    void playerAction() {

        player.disStatus();
        std::cout << std::string(10, '-') << std::endl;
        for (int i = 0; i < monsters.size(); i++) {
            std::cout << i << ": ";
            monsters[i]->disStatus();
        }
        player.goAttack(monsters);
        for (auto it = monsters.begin(); it != monsters.end();) {
            if ((*it)->getHp() <= 0) {
                it = monsters.erase(it);
            } else {
                ++it;
            }
        }
    }
    void monstersAction() {
        for (int i = 0; i < monsters.size(); i++) {
            monsters[i]->attackPlayer(player);
        }
    }
    bool isOver(const std::vector<std::unique_ptr<Monster>> &monsters,
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
};
int main() {
    std::cout << "Hello 地牢世界" << std::endl;
    Player p1("merlin", 100, 15);
    Game game(p1);
    game.monsters.push_back(std::make_unique<Orc>("兽人战士", 100, 5));
    game.monsters.push_back(std::make_unique<Goblin>("哥布林斥候", 30, 2));
    game.monsters.push_back(std::make_unique<Goblin>("哥布林斥候", 30, 2));
    game.monsters.push_back(std::make_unique<Goblin>("哥布林斥候", 30, 2));
    game.start();

    return 0;
}
