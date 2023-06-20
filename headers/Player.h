//
// Created by Martin Banaś on 15/06/2023.
//

#ifndef KASYNO_PLAYER_H
#define KASYNO_PLAYER_H
#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int accountBalance;
    int bet;
    int totalWonMoney;
public:
    Player();
    Player(string name);
    void setAccountBalance();
    int updateAccountBalance(int newBalance);
    void loseMoney(int money);
    void wonMoney(int money);
    string getName();
    int getAccountBalance();
    int placeBet();
    int getBet();
    void calculateWinnings(int money);
    string playerToWrite();


};


#endif //KASYNO_PLAYER_H
