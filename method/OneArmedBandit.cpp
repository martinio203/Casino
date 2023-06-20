
#include "../headers/OneArmedBandit.h"

OneArmedBandit::OneArmedBandit() {}

void OneArmedBandit::placeBet(Player &player) {
    bool betting = true;
    do {
        cout << "Postaw zakład: \n";
        cin >> bet;
        if (bet <= player.getAccountBalance()) {
            cout << "Twój zakład to " << bet << endl;
            betting = false;
        } else {
            cout << "Nie masz wystarczająco środków, dostępne środki: "
                 << player.getAccountBalance() << endl;
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

void OneArmedBandit::checkWin(Player &player) {
    if (roller1 == roller2 && roller2 == roller3) {
        cout << "Wygrałeś! Trafiłeś 3 identyczne liczby \n";
        player.wonMoney(OneArmedBandit::bet * 3);
    } else if (roller1 == roller2 || roller2 == roller3 || roller1 == roller3){
        cout << "Wygrałeś! Trafiłeś 2 identyczne liczby \n";
        player.wonMoney(OneArmedBandit::bet * 2);
    } else {
        cout << "Przegrałeś! Nie trafiłeś żadnej identycznej liczby \n";
        player.loseMoney(OneArmedBandit::bet);
    }
}

void OneArmedBandit::game(Player &player) {
    char ch;
    bool gameContinue;
    do {
        OneArmedBandit::placeBet(player);
        OneArmedBandit::roll();
        OneArmedBandit::displayRolls();
        OneArmedBandit::checkWin(player);
        cout << "Chcesz zagrać ponownie? (y/n) \n";
        cin >> ch;
        if  (tolower(ch) == 'y') gameContinue = true;
        else gameContinue = false;
    } while (gameContinue);
}