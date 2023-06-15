#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

class Player{
private:
    string name;
    int accountBalance;

public:
    Player(string name = "Nieznany gracz"){
        setName(name);
        setAccountBalance();
    }
    void setName(string name) {
        cout << "Podaj nazwe gracza: " << endl;
        cin >> name;
        Player::name = name;
    }

    void setAccountBalance() {
        srand((unsigned) time(NULL));
        Player::accountBalance = 500 + (rand() % 1000);
    }

    string getName(){
        return name;
    }

    int getAccountBalance(){
        return accountBalance;
    }
};

class Blackjack : public Player{
private:
    const int cards = 52;
    struct Card{
        string name;
        int value;
    };

public:
    Blackjack(){};
    vector<Card> deck {
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

    vector<Card> playerHand;
    vector<Card> computerHand;

    void shuffle(){
        random_device rd;
        mt19937 rng(rd());
        ::shuffle(deck.begin(), deck.end(), rng);
    }

    void dealPlayerCards(){
        if (!deck.empty()) cout << "Dostajesz";
    }
};

int main() {
    int choice;
    bool shouldContinue = true;
    Player player;
    Blackjack blackjack;
    blackjack.shuffle();
    while (shouldContinue){
        cout << "\nPodaj wybór: \n";
        cout << "1. Stanowisko z Blackjack'iem \n";
        cout << "2. Stanowisko dla jednorękiego bandyty \n";
        cout << "3. Stanowisko do ruletki \n";
        cout << "4. Najlepsi gracze \n";
        cout << "5. Wyjscie z kasyna \n";

        cin >> choice;
        switch(choice) {
            case 1: {
                break;
            }
            case 2:{
                break;}
            case 3:{
                cout << 3 << endl;
                break;
            }
            case 4:{
                cout << 4 << endl;
                break;}
            case 5:{
                shouldContinue = false;
                break;
            }
            default:
                if (isdigit(choice)) cout << "Podano litere zamiast liczby, ponownie ";
                else cout << "Nieprawidłowa liczba, ponownie ";
                break;
        }
    }
    return 0;
}
