#include "../headers/Player.h"

Player::Player() : name("Gracz"){
   Player::setAccountBalance();
}

Player::Player(string name) : name(name){
    setAccountBalance();
}

void Player::setAccountBalance() {
    srand((unsigned) time(NULL));
    accountBalance = 500 + (rand() % 1000);
}

void Player::loseMoney(int money) {
    cout << "Przegrałeś " << money << " pieniędzy \n";
    accountBalance -= money;
    cout << "Twoje dostępne konto: " << getAccountBalance() << endl;
}

void Player::wonMoney(int money) {
    cout << "Wygrałeś " << money << " pieniędzy \n";
    accountBalance += money;
    cout << "twoje dostępne konto: " << getAccountBalance() << endl;
    calculateWinnings(money);
}

int Player::updateAccountBalance(int newBalance) {
   return accountBalance = newBalance;
}

string Player::getName(){
    return name;
}

int Player::getAccountBalance() {
    return accountBalance;
}

int Player::placeBet() {
    bool betting = true;
    do{
        cout << "Postaw zakład: \n";
        cin >> bet;
        if (bet <= getAccountBalance()) {
            cout << "Twój zakład to " << bet << endl;
            betting = false;
        } else {
            cout << "Nie masz wystarczająco środków, dostępne środki: "
            << getAccountBalance() << endl;
        }
    } while (betting);
    return bet;
}

int Player::getBet() {
    return bet;
}

void Player::calculateWinnings(int money) {
    totalWonMoney += money;
}

string Player::playerToWrite() {
    return "Nazwa gracza: " + getName() + " " + "Stan konta: " + to_string(getAccountBalance())
    + " " + "Wygrane pieniądze: " + to_string(totalWonMoney);
}