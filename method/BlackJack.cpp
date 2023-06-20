#include "../headers/BlackJack.h"

BlackJack::BlackJack(){
    cards = {
            //pik 0-12
            {"Dwójka - Pik ♠", 2}, {"Trójka - Pik ♠", 3},
            {"Czwórka - Pik ♠", 4}, {"Piątka - Pik ♠", 5},
            {"Szóstka - Pik ♠", 6}, {"Siódemka - Pik ♠", 7},
            {"Ósemka - Pik ♠", 8}, {"Dziewiątka - Pik ♠", 9},
            {"Dziesiątka - Pik ♠", 10}, {"Walet - Pik ♠", 10},
            {"Dama - Pik ♠", 10}, {"Król - Pik ♠", 10},
            {"As - Pik ♠", 11},

            //kier 13-25
            {"Dwójka - Kier ♥", 2}, {"Trójka - Kier ♥", 3},
            {"Czwórka - Kier ♥", 4}, {"Piątka - Kier ♥", 5},
            {"Szóstka - Kier ♥", 6}, {"Siódemka - Kier ♥", 7},
            {"Ósemka - Kier ♥", 8}, {"Dziewiątka - Kier ♥", 9},
            {"Dziesiątka - Kier ♥", 10}, {"Walet - Kier ♥", 10},
            {"Dama - Kier ♥", 10}, {"Król - Kier ♥", 10},
            {"As - Kier ♥", 11},

            //trefl 26-38
            {"Dwójka - Trefl ♣", 2}, {"Trójka - Trefl ♣", 3},
            {"Czwórka - Trefl ♣", 4}, {"Piątka - Trefl ♣", 5},
            {"Szóstka - Trefl ♣", 6}, {"Siódemka - Trefl ♣", 7},
            {"Ósemka - Trefl ♣", 8}, {"Dziewiątka - Trefl ♣", 9},
            {"Dziesiątka - Trefl ♣", 10}, {"Walet - Trefl ♣", 10},
            {"Dama - Trefl ♣", 10}, {"Król - Trefl ♣", 10},
            {"As - Trefl ♣", 11},

            //karo 39-51
            {"Dwójka - Karo ♦", 2}, {"Trójka - Karo ♦", 3},
            {"Czwórka - Karo ♦", 4}, {"Piątka - Karo ♦", 5},
            {"Szóstka - Karo ♦", 6}, {"Siódemka - Karo ♦", 7},
            {"Ósemka - Karo ♦", 8}, {"Dziewiątka - Karo ♦", 9},
            {"Dziesiątka - Karo ♦", 10}, {"Walet - Karo ♦", 10},
            {"Dama - Karo ♦", 10}, {"Król - Karo ♦", 10},
            {"As - Karo ♦", 11}
    };
   setDeck();
}

void BlackJack::setDeck(){
    deck.clear();
    deck = cards;
}

void BlackJack::shuffle() {
    random_device rd;
    mt19937 rng(rd());
    ::shuffle(deck.begin(), deck.end(), rng);
}

void BlackJack::dealPlayerCard() {
    playerHand.push_back(deck.back());
    cout << "Dostajesz " << playerHand.back().name << endl;
    deck.pop_back();
}

void BlackJack::dealComputerCard() {
    computerHand.push_back(deck.back());
    cout << "Krupier dostaje " << computerHand.back().name << endl << endl;
    deck.pop_back();
    if (computerHand.size() == 2) cout << "Komputer posiada "
        << calculateComputerHand() << " punktów \n";
}

void BlackJack::clearHands() {
    playerHand.clear();
    computerHand.clear();
}


int BlackJack::calculatePlayerHand() {
    int sumHand = 0;
    for (Card &card : playerHand) {
        sumHand += card.value;
    }
    return sumHand;
}

int BlackJack::calculateComputerHand(){
    int sumHand = 0;
    for (Card &card : computerHand) {
        sumHand += card.value;
    }
    return sumHand;
}

void BlackJack::dealing(){
    char ch;
   dealPlayerCard();
    do {
        if (calculatePlayerHand() < 21) {
            cout << "Aktualnie posiadasz " <<
                 calculatePlayerHand() << " punkty" << endl;
            cout << "Chcesz dobrać karte? (y/n): \n";
            cin >> ch;
            if (tolower(ch) == 'y') dealPlayerCard();
        }
    } while ((tolower(ch) == 'y' && calculatePlayerHand() < 21));
}

void BlackJack::checkWinner(Player &player) {
    if (calculatePlayerHand() > calculateComputerHand()
        && calculatePlayerHand() < 21){
        cout << "Wygrałeś! Masz o "<<
        calculatePlayerHand() - calculateComputerHand() <<
        " punktów więcej od komputera \n";
        player.wonMoney(player.getBet());

    } else if (calculatePlayerHand() < calculateComputerHand()) {
        cout << "Przegrałeś! Masz o " << calculateComputerHand() - calculatePlayerHand()
        << " punktów mniej od komputera \n";
        player.loseMoney(player.getBet());

    } else if (calculatePlayerHand() > 21) {
        cout << "Przegrałeś! Masz o " << calculatePlayerHand() - 21
        << " punktów za dużo \n";
        player.loseMoney(player.getBet());

    } else if (calculatePlayerHand() == 21) {
        cout << "Blackjack! Masz 21 punktów \n";
        player.wonMoney(player.getBet());

    } else if (calculatePlayerHand() == calculateComputerHand()){
        cout << "Remis! Komputer posiada taką samą liczbę punktów. \n";
    }
}

void BlackJack::game(Player &player) {
    bool gameContinue;
    char ch;
    do {
        shuffle();
        player.placeBet();
        dealComputerCard();
        dealing();
        dealComputerCard();
        checkWinner(player);
        clearHands();
        cout << "Chcesz zagrać ponownie? (y/n): \n";
        cin >> ch;

        if (tolower(ch) == 'y' && player.getAccountBalance() > 0) {
            gameContinue = true;
        } else if (tolower(ch) == 'y' && player.getAccountBalance() == 0){
            cout << "Nie masz pieniędzy na koncie \n";
            gameContinue = false;
        } else gameContinue = false;


    } while (gameContinue);
}


