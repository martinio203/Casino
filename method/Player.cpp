#include "../headers/Player.h"

Player::Player() : name("Gracz"){
   Player::setAccountBalance();
}

Player::Player(string name) : name(name){
    Player::setAccountBalance();
}

void Player::setAccountBalance() {
    srand((unsigned) time(NULL));
    Player::accountBalance = 500 + (rand() % 1000);
}

void Player::loseMoney(int money) {
    cout << "Przegrałeś " << money << " pieniędzy \n";
    accountBalance -= money;
    cout << "Twoje dostępne konto: " << Player::getAccountBalance() << endl;
}

void Player::wonMoney(int money) {
    cout << "Wygrałeś " << money << " pieniędzy \n";
    Player::accountBalance += money;
    cout << "twoje dostępne konto: " << Player::getAccountBalance() << endl;

}

int Player::updateAccountBalance(int newBalance) {
   return Player::accountBalance = newBalance;
}

string Player::getName(){
    return Player::name;
}

int Player::getAccountBalance() {
    return Player::accountBalance;
}