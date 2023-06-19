
#include "../headers/Roulette.h"

Roulette::Roulette() {
    //green, red, black
    numbers = {
             0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11,
             30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18,
             29, 7, 28, 12, 35, 3, 26
    };
    colorName = {
            {'r', "czerwone"},
            {'b', "czarne"},
            {'g', "zielone"}
    };
}

void Roulette::placeBet() {
    bool cont = true;
    do {
        cout << "Postaw zakład: \n";
        cin >> bet;
        if (bet > Player::getAccountBalance())
            cout << "Nie posiadasz środków, posiadane środki: " << Player::getAccountBalance() << endl;
        else {
            cont = false;
        }
    }while (cont);
}

string Roulette::checkNumberColor(int number) {
    int index;
    for (int i = 0; i < numbers.size(); ++i) {
        if (number == numbers[i]) index = i;
    }
    if (index == 0) return "zielone";
    else if (index % 2 == 0) return "czarne";
    else return "czerwone";
}

void Roulette::spin() {
    srand((unsigned) time(NULL));
    Roulette::randomNumber = (rand() % 36);
}

string Roulette::checkPlayerColor(char c) {
    auto it = std::find_if(colorName.begin(), colorName.end(), [c](const checkColorName& ccn) {
        return ccn.chosenName == c;
    });
    return it -> name;
}

void Roulette::checkWinner(char c) {
    if (Roulette::checkPlayerColor(c) == Roulette::checkNumberColor(Roulette::randomNumber)){
        cout << "Wygrałeś! Postawiłeś kolor " << Roulette::checkPlayerColor(c)
        << " a komputer wybrał " << Roulette::checkNumberColor(Roulette::randomNumber)
        << " " << Roulette::randomNumber << endl;
        Player::wonMoney(Roulette::bet);
    } else{
        cout << "Przegrałeś! Postawiłeś kolor " << Roulette::checkPlayerColor(c)
             << " a komputer wybrał " << Roulette::checkNumberColor(Roulette::randomNumber)
             << " " << Roulette::randomNumber << endl;
        Player::loseMoney(Roulette::bet);
    }
}

void Roulette::game() {
    char c, cont;
    bool gameContinue;
    do {
        Roulette::placeBet();
        cout << "Wybierz kolor czerwony, czarny albo zielony: (r/b/g) \n";
        cin >> c;
        Roulette::spin();
        Roulette::checkWinner(c);

        cout << "Chcesz zagrać ponownie? (y/n) \n";
        cin >> cont;
        if  (tolower(cont) == 'y') gameContinue = true;
        else gameContinue = false;
    } while (gameContinue);
}

