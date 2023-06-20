
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
    randomNumber = (rand() % 36);
}

string Roulette::checkPlayerColor(char c) {
    auto it = find_if(colorName.begin(), colorName.end(), [c](const checkColorName& ccn) {
        return ccn.chosenName == c;
    });
    return it -> name;
}

void Roulette::checkWinner(char c, Player &player) {
    if (checkPlayerColor(c) == checkNumberColor(randomNumber)){
        cout << "Wygrałeś! Postawiłeś kolor " << checkPlayerColor(c)
        << " a komputer wybrał " << checkNumberColor(randomNumber)
        << " " <<randomNumber << endl;
        player.wonMoney(player.getBet());
    } else if (checkPlayerColor(c) == checkNumberColor(randomNumber)
    && c == 'g') {
        player.wonMoney(player.getBet() * 14);
    }else{
        cout << "Przegrałeś! Postawiłeś kolor " << checkPlayerColor(c)
             << " a komputer wybrał " << checkNumberColor(randomNumber)
             << " " << randomNumber << endl;
        player.loseMoney(player.getBet());
    }
}

void Roulette::game(Player &player) {
    char c, cont;
    bool gameContinue;
    do {
        player.placeBet();
        cout << "Wybierz kolor czerwony, czarny albo zielony: (r/b/g) \n";
        cin >> c;
        spin();
        checkWinner(c, player);

        cout << "Chcesz zagrać ponownie? (y/n) \n";
        cin >> cont;
        if  (tolower(cont) == 'y' && player.getAccountBalance() > 0) gameContinue = true;
        else if (tolower(cont) == 'y' && player.getAccountBalance() == 0){
            cout << "Nie masz pieniędzy na koncie \n";
            gameContinue = false;
        } else gameContinue = false;
    } while (gameContinue);
}

