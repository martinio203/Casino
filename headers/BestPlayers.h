
#ifndef KASYNO_BESTPLAYERS_H
#define KASYNO_BESTPLAYERS_H
#include <iostream>
#include "Player.h"
#include <fstream>

using namespace std;

class BestPlayers : public Player{
private:
    fstream file;
    string line;
public:
    void readFile();
    void writeToFile(Player &player);
};


#endif //KASYNO_BESTPLAYERS_H
