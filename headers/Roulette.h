//
// Created by Martin Banaś on 18/06/2023.
//

#ifndef KASYNO_ROULETTE_H
#define KASYNO_ROULETTE_H
#include "Player.h"

class Roulette : public Player{
private:
    vector<int> numbers;
    struct checkColorName{
        char chosenName;
        string name;
    };
    vector<checkColorName> colorName;
    int bet;
    int randomNumber;
public:
    Roulette();
    void placeBet(Player &player);
    string checkNumberColor(int number);
    void spin();
    void checkWinner(char c, Player &player);
    void game(Player &player);
    string checkPlayerColor(char c);

};


#endif //KASYNO_ROULETTE_H
