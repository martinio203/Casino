
#ifndef KASYNO_BLACKJACK_H
#define KASYNO_BLACKJACK_H
#include <iostream>
#include <random>
#include "Player.h"
using namespace std;

class BlackJack : public Player{
private:
    int bet;
    struct Card{
        string name;
        int value;
    };

public:
    BlackJack();
    vector<Card> cards;
    vector<Card> deck;
    vector<Card> playerHand;
    vector<Card> computerHand;

    void shuffle();
    void dealPlayerCard();
    void dealComputerCard();
    void clearHands();
    void placeBet();
    int calculatePlayerHand();
    int calculateComputerHand();
    void dealing();
    void checkWinner();
    void game();


};


#endif //KASYNO_BLACKJACK_H