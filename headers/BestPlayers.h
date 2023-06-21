
#ifndef KASYNO_BESTPLAYERS_H
#define KASYNO_BESTPLAYERS_H
#include <iostream>
#include "Player.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class BestPlayers : public Player{
private:
    fstream file;
    string line;
    vector<string> fileData;
public:
    void writeToFile(string player);
    void addFileDataToVector();
    int splitLineMoney(string fileLine);
    void sortingBestPlayers();
    void updateFile();
    void readFile();
    void displayBestPlayers();

};


#endif //KASYNO_BESTPLAYERS_H
