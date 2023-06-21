#include <iostream>
#include "headers/Player.h"
#include "headers/BlackJack.h"
#include "headers/Roulette.h"
#include "headers/OneArmedBandit.h"
#include "headers/BestPlayers.h"
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
    BestPlayers bestplayers;
    cout << "Masz " << player.getAccountBalance() << " pieniędzy \n";
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
                if (player.getAccountBalance() > 0)
                    blackjack.game(player);
                else cout << "Nie możesz zagrać z powodu braku pieniędzy \n";
                break;
            }
            case 2:{
                if (player.getAccountBalance() > 0)
                    onearmedbandit.game(player);
                else cout << "Nie możesz zagrać z powodu braku pieniędzy \n";
                break;
            }
            case 3:{
                if (player.getAccountBalance() > 0)
                    roulette.game(player);
                else cout << "Nie możesz zagrać z powodu braku pieniędzy \n";
                break;
            }
            case 4:{
                bestplayers.writeToFile(player.playerToWrite());
                bestplayers.displayBestPlayers();
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
