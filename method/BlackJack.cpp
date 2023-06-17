#include "../headers/BlackJack.h"

BlackJack::BlackJack() {
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
    deck = cards;
};

void BlackJack::shuffle() {
    random_device rd;
    mt19937 rng(rd());
    ::shuffle(deck.begin(), deck.end(), rng);
}

void BlackJack::dealPlayerCard() {
    BlackJack::playerHand.push_back(deck.back());
    cout << "Dostajesz " << BlackJack::playerHand.back().name << endl;
    deck.pop_back();
}

void BlackJack::dealComputerCard() {
    BlackJack::computerHand.push_back(deck.back());
    if (BlackJack::computerHand.size() == 1)
        cout << "Komputer dostaje " << BlackJack::computerHand.back().name << endl;
    deck.pop_back();
}

void BlackJack::placeBet() {
    bool betting = true;
    do {
        cout << "Postaw zaklad: \n";
        cin >> bet;
        if (bet > Player::getAccountBalance()) {
            cout << "Twój bet to " << bet << endl;
            betting = false;
        }
        else{
            cout << "Nie masz wystarczająco środków, dostępne środki: "
            << Player::getAccountBalance();
        }
    } while(betting);
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
    do {
        BlackJack::dealPlayerCard();
        cout << "Chcesz dobrać karte? (y/n): \n";
        cin >> ch;
        if (BlackJack::calculatePlayerHand() < 21) {
            cout << "Aktualnie posiadasz " <<
                 BlackJack::calculatePlayerHand() <<
                 " punktów. By wygrać musisz dostać kartę o wartości niższej niż "
                 << 21 - BlackJack::calculatePlayerHand() << endl;
        } else if (BlackJack::calculatePlayerHand() > 21) {
            cout << "Masz o " << BlackJack::calculatePlayerHand() - 21 << " punktów za dużo" << endl;
        }
    } while ((tolower(ch) == 'y' && BlackJack::calculatePlayerHand() < 21));
    BlackJack::checkWinner();
}

void BlackJack::checkWinner() {
    if (BlackJack::calculatePlayerHand() > BlackJack::calculateComputerHand()
        || BlackJack::calculatePlayerHand() == 21){
        cout << "Wygrałeś! " << bet << " monet\n";
        Player::wonMoney(bet);
    } else {
        cout << "Masz o " << BlackJack::calculateComputerHand()-BlackJack::calculatePlayerHand()
        << " monet za mało";
        Player::loseMoney(bet);
    }
}

void BlackJack::game() {
    bool gameContinue;
    char ch;
    do {
        if (Player::getAccountBalance() == 0) {
            cout << "Nie posiadasz środków do gry. \n";
            gameContinue = false;
        } else{
            BlackJack::shuffle();
            BlackJack::placeBet();
            BlackJack::dealComputerCard();
            BlackJack::dealing();
            BlackJack::dealComputerCard();
            BlackJack::checkWinner();

            cout << "Chcesz zagrać ponownie? (y/n): \n";
            cin >> ch;
            if (tolower(ch) == 'y') gameContinue = true;
            else gameContinue = false;
        }
    } while (gameContinue);

}


