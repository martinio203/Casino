
#include "../headers/OneArmedBandit.h"

OneArmedBandit::OneArmedBandit() {}

void OneArmedBandit::placeBet() {
    bool betting = true;
    do {
        cout << "Postaw zakład: \n";
        cin >> bet;
        if (bet <= Player::getAccountBalance()) {
            cout << "Twój zakład to " << bet << endl;
            betting = false;
        } else {
            cout << "Nie masz wystarczająco środków, dostępne środki: "
                 << Player::getAccountBalance() << endl;
        }
    } while (betting);
}

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

void OneArmedBandit::checkWin() {
    if (roller1 == roller2 && roller2 == roller3) {
        cout << "Wygrałeś! Trafiłeś 3 identyczne liczby \n";
    } else if (roller1 == roller2 || roller2 == roller3 || roller1 == roller3){
        cout << "Wygrałeś! Trafiłeś 2 identyczne liczby \n";
    } else {
        cout << "Przegrałeś! Nie trafiłeś żadnej identycznej liczby \n";
    }
}

void OneArmedBandit::game() {
    char ch;
    bool gameContinue;
    do {
        OneArmedBandit::placeBet();
        OneArmedBandit::roll();
        OneArmedBandit::displayRolls();
        OneArmedBandit::checkWin();
        cout << "Chcesz zagrać ponownie? (y/n) \n";
        cin >> ch;
        if  (tolower(ch) == 'y') gameContinue = true;
        else gameContinue = false;
    } while (gameContinue);
}