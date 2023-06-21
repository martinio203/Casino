#include "../headers/BestPlayers.h"

void BestPlayers::writeToFile(string player) {
    ofstream file;
    file.open("BestPlayers.txt", ios::app);
    if (file.is_open()) {
        file << player << endl;
    }
    file.close();
}

void BestPlayers::addFileDataToVector() {
    fstream file;
    string line;
    fileData.clear();
    file.open("BestPlayers.txt");
    if (file.good()){
        while (getline(file, line)){
            fileData.push_back(line);
        }
    }
    file.close();
}

int BestPlayers::splitLineMoney(string fileLine) {
    string word, lastWord;
    stringstream line(fileLine);
    while (line >> word) lastWord = word;
    return stoi(word);
}

void BestPlayers::sortingBestPlayers() {
    string pom;
    for(int i = 0; i < fileData.size(); i++) {
        for (int j = 0; j < fileData.size() - 1; j++) {
            if (splitLineMoney(fileData[j]) < splitLineMoney(fileData[j + 1])){
                pom = fileData[j];
                fileData[j] = fileData[j + 1];
                fileData[j + 1] = pom;
            }
        }
    }
}

void BestPlayers::updateFile() {
    fstream file;
    file.open("BestPlayers.txt", std::ofstream::out | std::ofstream::trunc);
    if (file.is_open()) {
        for (int i = 0; i < fileData.size(); ++i) {
            file << fileData[i] << endl;
        }
    }
    file.close();
}

void BestPlayers::readFile() {
    file.open("BestPlayers.txt");
    if (file.good()){
        while (getline(file, line)){
            cout << line << endl;
        }
    }
    file.close();
}

void BestPlayers::displayBestPlayers() {
    addFileDataToVector();
    sortingBestPlayers();
    updateFile();
    readFile();
}
