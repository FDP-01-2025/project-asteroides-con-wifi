#ifndef MEMORAMA_H
#define MEMORAMA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int BOARD_SIZE = 4;
const int TOTAL_PAIRS = BOARD_SIZE * BOARD_SIZE / 2;

struct Card {
    char word[20];
    bool revealed;
};

class Memorama {
private:
    Card board[BOARD_SIZE][BOARD_SIZE];
    char words[TOTAL_PAIRS][20] = {
        "AI", "Logic", "Model", "Neuron",
        "Data", "Train", "Learn", "Code"
    };
    int score;

    void shuffleBoard() {
        char tempWords[BOARD_SIZE * BOARD_SIZE][20];
        int index = 0;

        for (int i = 0; i < TOTAL_PAIRS; ++i) {
            strcpy(tempWords[index++], words[i]);
            strcpy(tempWords[index++], words[i]);
        }

        for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
            int r = rand() % (BOARD_SIZE * BOARD_SIZE);
            char temp[20];
            strcpy(temp, tempWords[i]);
            strcpy(tempWords[i], tempWords[r]);
            strcpy(tempWords[r], temp);
        }

        index = 0;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                strcpy(board[i][j].word, tempWords[index++]);
                board[i][j].revealed = false;
            }
        }
    }

    void displayHeader() {
        cout << R"(
  , _ ,
 ( o o )
/'`---'`\
|       |
|       |
 \     /
  `~~~`
)" << endl;
    }

    void displayBoard(bool revealAll = false) {
        cout << "\n   ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << " " << j + 1 << "   ";
        }
        cout << "\n";

        for (int i = 0; i < BOARD_SIZE; ++i) {
            cout << " " << char('A' + i) << " ";
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j].revealed || revealAll) {
                    printf(" %-4s", board[i][j].word);
                } else {
                    cout << " [ ] ";
                }
            }
            cout << "\n";
        }
    }

    void waitForEnter() {
        cout << "\nPress ENTER to continue...";
        cin.ignore();
        cin.get();
    }

    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    bool isValidInput(string input) {
        if (input.length() != 2) return false;
        char row = toupper(input[0]);
        char col = input[1];
        return (row >= 'A' && row < 'A' + BOARD_SIZE) && (col >= '1' && col < '1' + BOARD_SIZE);
    }

    void getCoordinates(string input, int &x, int &y) {
        x = toupper(input[0]) - 'A';
        y = input[1] - '1';
    }

public:
    Memorama() {
        srand(time(NULL));
        score = 0;
        shuffleBoard();
    }

    void playGame() {
        int pairsFound = 0;
        string input1, input2;

        clearScreen();
        displayHeader();

        while (pairsFound < TOTAL_PAIRS) {
            displayBoard();

            cout << "\nScore: " << score;
            cout << "\n\nChoose first card (e.g. A1): ";
            cin >> input1;

            if (!isValidInput(input1)) {
                cout << "Invalid input. Try again.\n";
                continue;
            }

            int x1, y1;
            getCoordinates(input1, x1, y1);
            if (board[x1][y1].revealed) {
                cout << "Card already revealed.\n";
                continue;
            }

            board[x1][y1].revealed = true;
            displayBoard();

            cout << "\nChoose second card (e.g. B3): ";
            cin >> input2;

            if (!isValidInput(input2)) {
                board[x1][y1].revealed = false;
                cout << "Invalid input. Try again.\n";
                continue;
            }

            int x2, y2;
            getCoordinates(input2, x2, y2);
            if (x1 == x2 && y1 == y2 || board[x2][y2].revealed) {
                board[x1][y1].revealed = false;
                cout << "Invalid selection.\n";
                continue;
            }

            board[x2][y2].revealed = true;
            displayBoard();

            if (strcmp(board[x1][y1].word, board[x2][y2].word) == 0) {
                cout << "\nGreat! You found a match!";
                score += 10;
                pairsFound++;
            } else {
                cout << "\nNot a match...";
                score -= 2;
                board[x1][y1].revealed = false;
                board[x2][y2].revealed = false;
            }

            waitForEnter();
            clearScreen();
            displayHeader();
        }

        cout << "\nCONGRATULATIONS! You completed the game.";
        cout << "\nFinal Score: " << score << "\n";
    }

    int getScore() {
        return score;
    }
};

#endif
