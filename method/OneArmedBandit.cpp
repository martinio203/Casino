
#include "../headers/OneArmedBandit.h"

OneArmedBandit::OneArmedBandit() {}


void OneArmedBandit::roll() {
    roller1 = rand() % 10 + 1;
    roller2 = rand() % 10 + 1;
    roller3 = rand() % 10 + 1;
}

void OneArmedBandit::displayRolls() {
    cout << "Wylosowne liczby: " << roller1 << flush;
    this_thread::sleep_for(chrono::seconds(1));
    cout << " " << roller2 << flush;
    this_thread::sleep_for(chrono::seconds(1));
    cout << " " << roller3 << endl;
}

void OneArmedBandit::checkWin(Player &player) {
    if (roller1 == roller2 && roller2 == roller3) {
        cout << "Wygrałeś! Trafiłeś 3 identyczne liczby \n";
        player.winMoney(player.getBet() * 3);
    } else if (roller1 == roller2 || roller2 == roller3 || roller1 == roller3){
        cout << "Wygrałeś! Trafiłeś 2 identyczne liczby \n";
        player.winMoney(player.getBet() *  2);
    } else {
        cout << "Przegrałeś! Nie trafiłeś żadnej identycznej liczby \n";
        player.loseMoney(player.getBet());
    }
}

void OneArmedBandit::game(Player &player) {
    char ch;
    bool gameContinue;
    do {
        player.placeBet();
        roll();
        displayRolls();
        checkWin(player);
        if (player.getAccountBalance() > 0) {
            cout << "Chcesz zagrać ponownie? (y/n) \n";
            cin >> ch;
        }
        if  (tolower(ch) == 'y' && player.getAccountBalance() > 0) gameContinue = true;
        else if (tolower(ch) == 'y' && player.getAccountBalance() == 0){
            cout << "Nie masz pieniędzy na koncie \n";
            gameContinue = false;
        }
        else gameContinue = false;
    } while (gameContinue);
}