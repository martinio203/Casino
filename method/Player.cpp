#include "../headers/Player.h"

Player::Player() : name("Nieznany gracz"), accountBalance(10){};

Player::Player(string name){
    Player::setName();
    Player::setAccountBalance();
}

void Player::setName() {
    Player::name = name;
}

void Player::setAccountBalance() {
    srand((unsigned) time(NULL));
    Player::accountBalance = 500 + (rand() % 1000);
}

void Player::loseMoney(int money) {
    cout << "Przegrałeś " << money << " pieniędzy "
    << "twoje dostępne konto: " << Player::getAccountBalance();
    Player::accountBalance -= money;
}

void Player::wonMoney(int money) {
    cout << "Wygrałeś " << money << " pieniędzy "
         << "twoje dostępne konto: " << Player::getAccountBalance();
    Player::accountBalance += money;
}

string Player::getName(){
    return Player::name;
}

int Player::getAccountBalance() {
    return Player::accountBalance;
}