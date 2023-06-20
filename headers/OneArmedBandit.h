
#ifndef KASYNO_ONEARMEDBANDIT_H
#define KASYNO_ONEARMEDBANDIT_H
#include "Player.h"
#include <chrono>
#include <thread>

class OneArmedBandit : public Player{
private:
    int bet;
    int roller1, roller2, roller3;
public:
    OneArmedBandit();
    void placeBet(Player &player);
    void roll();
    void displayRolls();
    void checkWin(Player &player);
    void game(Player &player);
};


#endif //KASYNO_ONEARMEDBANDIT_H
