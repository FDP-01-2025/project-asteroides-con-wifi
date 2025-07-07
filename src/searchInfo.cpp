#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
#include "searchInfo.h"
#include "utils.h"

using namespace std;

string boardWords[3][3];
bool revealed[3][3];
int pairsFound = 0;

string words[5] = { "Logic", "IA", "Rocket", "Space", "Bonus" };

void initializeGame() {
    string values[9] = {
        "Logic", "Logic",
        "IA", "IA",
        "Rocket", "Rocket",
        "Space", "Space",
        "Bonus"
    };

    srand(time(0));
    for (int i = 0; i < 9; i++) {
        int pos = rand() % 9;
        string temp = values[i];
        values[i] = values[pos];
        values[pos] = temp;
    }

    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            boardWords[i][j] = values[index];
            revealed[i][j] = false;
            index++;
        }
    }
}

void showBoard() {
    system("cls");
    cout << "=== MISSION KEPLER-45: AI DATA SEARCH ===\n";
    cout << "Agent Noctriz | Pairs Found: " << pairsFound << "/4\n";
    cout << "Current Score: " << globalScore << "\n\n";

    cout << "   A   B   C\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            if (revealed[i][j]) {
                cout << boardWords[i][j] << " ";
            } else {
                cout << "[ ] ";
            }
        }
        cout << "\n";
    }
}

void play() {
    system("cls");
    cout << "Noctriz has arrived at Kepler-45. This planet holds the key to understanding the AI.\n";
    cout << "You must find pairs of data to unlock vital information about the enemy.\n";
    cout << "Concentrate, every piece of information is crucial!\n\n";
    waitForEnter();

    initializeGame();
    pairsFound = 0;
    globalScore = 0;

    auto getCoords = [](string input, int& row, int& col) -> bool {
        if (input.length() != 2) return false;
        char c = toupper(input[0]);
        char r = input[1];
        if (c < 'A' || c > 'C' || r < '1' || r > '3') return false;
        col = c - 'A';
        row = r - '1';
        return true;
    };

    while (pairsFound < 4) {
        showBoard();

        string input;
        int row1, col1, row2, col2;

        // PRIMERA CARTA
        while (true) {
            cout << "\nChoose first card (e.g., A1): ";
            cin >> input;
            if (!getCoords(input, row1, col1)) {
                cout << "Invalid input. Use format A1 to C3.\n";
                continue;
            }
            if (revealed[row1][col1]) {
                cout << "Card already revealed. Choose another.\n";
                continue;
            }
            break;
        }

        revealed[row1][col1] = true;
        showBoard();

        // SEGUNDA CARTA
        while (true) {
            cout << "\nChoose second card (e.g., B2): ";
            cin >> input;
            if (!getCoords(input, row2, col2)) {
                cout << "Invalid input. Use format A1 to C3.\n";
                continue;
            }
            if (revealed[row2][col2]) {
                cout << "Card already revealed. Choose another.\n";
                continue;
            }
            if (row1 == row2 && col1 == col2) {
                cout << "Cannot choose the same card twice.\n";
                continue;
            }
            break;
        }

        revealed[row2][col2] = true;

        // Mostrar ambas cartas
        system("cls");
        cout << "=== MISSION KEPLER-45: AI DATA SEARCH ===\n";
        cout << "Agent Noctriz | Pairs Found: " << pairsFound << "/4\n";
        cout << "Current Score: " << globalScore << "\n\n";
        cout << "   A   B   C\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << "  ";
            for (int j = 0; j < 3; j++) {
                if (revealed[i][j]) {
                    cout << boardWords[i][j] << " ";
                } else {
                    cout << "[ ] ";
                }
            }
            cout << "\n";
        }

        cout << "\nCard 1: " << boardWords[row1][col1];
        cout << " | Card 2: " << boardWords[row2][col2] << "\n";

        // Comparar
        if (boardWords[row1][col1] == boardWords[row2][col2]) {
            if (boardWords[row1][col1] == "Bonus") {
                cout << "\nBONUS FOUND! +10 points!\n";
                globalScore += 10;
            } else {
                cout << "\nPAIR FOUND! Excellent work, Noctriz!\n";
                globalScore += 100;
                pairsFound++;
            }
        } else {
            cout << "\nNot a match. Keep trying!\n";
            waitForEnter();
            revealed[row1][col1] = false;
            revealed[row2][col2] = false;
            globalScore -= 25;
        }

        waitForEnter();
    }

    system("cls");
    cout << "=======================================\n";
    cout << "       MISSION KEPLER-45: AI DATA\n";
    cout << "=======================================\n\n";
    cout << "MISSION COMPLETE!\n";
    cout << "You've unlocked critical knowledge about the AI.\n";
    cout << "Mission Score: " << globalScore << "\n";
    waitForEnter();
}