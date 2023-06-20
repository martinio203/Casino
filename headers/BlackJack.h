
#ifndef KASYNO_BLACKJACK_H
#define KASYNO_BLACKJACK_H
#include <iostream>
#include <random>
#include "Player.h"
using namespace std;

class BlackJack : public Player{
private:
    struct Card{
        string name;
        int value;
    };
    vector<Card> cards;
    vector<Card> deck;
    vector<Card> playerHand;
    vector<Card> computerHand;

public:
    BlackJack();

    void setDeck();
    void shuffle();
    void dealPlayerCard();
    void dealComputerCard();
    void clearHands();
    int calculatePlayerHand();
    int calculateComputerHand();
    void dealing();
    void checkWinner(Player &player);
    void game(Player &player);


};


#endif //KASYNO_BLACKJACK_H
