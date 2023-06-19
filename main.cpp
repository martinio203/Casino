#include <iostream>
#include "headers/Player.h"
#include "headers/BlackJack.h"
#include "headers/Roulette.h"
#include "headers/OneArmedBandit.h"
using namespace std;

int main() {
    int choice;
    string name;
    bool shouldContinue = true;

    cout << "Podaj nazwe gracza: \n";
    cin >> name;
    Player player(name);
    BlackJack blackjack;
    Roulette roulette;
    OneArmedBandit onearmedbandit;
    while (shouldContinue){
        cout << "\nPodaj wybór: \n";

        cout << "1. Stanowisko z Blackjack'iem \n";
        cout << "2. Stanowisko dla jednorękiego bandyty \n";
        cout << "3. Stanowisko do ruletki \n";
        cout << "4. Najlepsi gracze \n";
        cout << "5. Sprawdź dostępne środki \n";
        cout << "6. Wyjscie z kasyna \n";

        cin >> choice;
        switch(choice) {
            case 1: {
                blackjack.game();
                break;
            }
            case 2:{
                onearmedbandit.game();
                break;
            }
            case 3:{
                roulette.game();
                break;
            }
            case 4:{
                cout << 4 << endl;
                break;
            }
            case 5:{
                cout << "Dostępne środki: " << player.getAccountBalance();
                break;
            }
            case 6:{
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
