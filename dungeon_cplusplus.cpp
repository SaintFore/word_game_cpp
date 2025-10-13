#include <iostream>
#include <string>
#include <vector>

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

    void disStatus() {

        std::cout << std::string("玩家[") + name + "],生命[" << hp << "],攻击["
                  << attack << "]" << std::endl;
    }
    void takeDamage(int damage) { hp = hp - damage; }
    void goAttack(std::vector<Monster> &monsters) {
        int number = choeseMonster();
        if (number >= 0 && number < monsters.size()) {
            Monster &monster = monsters[number];
            monster.takeDamage(attack);
            std::cout << "[" + name + "]攻击了[" + monster.getName() + "]"
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

// Game
class Game {

  public:
    Player player;
    std::vector<Monster> monsters;
    Game(Player pPlayer) : player(pPlayer) {}
    void start() {
        while (true) {
            player.disStatus();
            std::cout << std::string(10, '-') << std::endl;
            for (int i = 0; i < monsters.size(); i++) {
                std::cout << i << ": ";
                monsters[i].disStatus();
            }
            player.goAttack(monsters);
            for (auto it = monsters.begin(); it != monsters.end();) {
                if (it->getHp() <= 0) {
                    it = monsters.erase(it);
                } else {
                    ++it;
                }
            }
            // std::erase_if(monsters,[](Monster & m){
            //     return m.getHp() <= 0;
            // })
            if (isOver(monsters)) {
                break;
            }
        }
    }
    bool isOver(const std::vector<Monster> &monsters) {
        if (monsters.size() == 0) {
            std::cout << "你讨伐了全部怪物! " << std::endl;
            return true;
        } else {
            return false;
        }
    }
};
int main() {
    std::cout << "Hello 地牢世界" << std::endl;
    Player p1("merlin", 100, 5);
    Monster slime("slime", 50, 2);
    Monster goblin("goblin", 20, 5);
    Game game(p1);
    game.monsters.push_back(slime);
    game.monsters.push_back(goblin);
    game.monsters.push_back(goblin);
    game.monsters.push_back(goblin);

    game.start();

    return 0;
}
