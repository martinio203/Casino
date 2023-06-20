
#include "../headers/BestPlayers.h"
void BestPlayers::readFile() {
    file.open("BestPlayers.txt");
    if (file.good()){
        while (getline(file, line)){
            cout << line << endl;
        }
    }
    file.close();
}

void BestPlayers::writeToFile(Player &player) {
    file.open("BestPlayers.txt", ios::app);
    if (file.is_open()) {
        file << player.playerToWrite() << endl;
    }
    file.close();
}

