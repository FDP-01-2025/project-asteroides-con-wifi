#ifndef MEMORAMA_H
#define MEMORAMA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

const int BOARD_ROWS = 3;
const int BOARD_COLS = 4;
const int TOTAL_PAIRS = (BOARD_ROWS * BOARD_COLS) / 2;

struct Card {
    char word[20];
    bool revealed;
};

class Memorama {
private:
    Card board[BOARD_ROWS][BOARD_COLS];
    char words[TOTAL_PAIRS][20] = {
        "AI", "Logic", "Model", "Neuron", "Data", "Train"
    };
    int score;

    void shuffleBoard() {
        char tempWords[BOARD_ROWS * BOARD_COLS][20];
        int index = 0;

        for (int i = 0; i < TOTAL_PAIRS; ++i) {
            strcpy(tempWords[index++], words[i]);
            strcpy(tempWords[index++], words[i]);
        }

        for (int i = 0; i < BOARD_ROWS * BOARD_COLS; ++i) {
            int r = rand() % (BOARD_ROWS * BOARD_COLS);
            char temp[20];
            strcpy(temp, tempWords[i]);
            strcpy(tempWords[i], tempWords[r]);
            strcpy(tempWords[r], temp);
        }

        index = 0;
        for (int i = 0; i < BOARD_ROWS; ++i) {
            for (int j = 0; j < BOARD_COLS; ++j) {
                strcpy(board[i][j].word, tempWords[index++]);
                board[i][j].revealed = false;
            }
        }
    }

    void displayHeader() {
        clearScreen();
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
        cout << "\n";
        char label = 'A';
        for (int i = 0; i < BOARD_ROWS; ++i) {
            for (int j = 0; j < BOARD_COLS; ++j) {
                if (board[i][j].revealed || revealAll) {
                    printf(" %-6s", board[i][j].word);
                } else {
                    printf(" [ %c ] ", label);
                }
                label++;
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

    bool isValidLetter(char input) {
        input = toupper(input);
        return (input >= 'A' && input < 'A' + BOARD_ROWS * BOARD_COLS);
    }

    void getCoordinatesFromChar(char input, int &row, int &col) {
        int pos = toupper(input) - 'A';
        row = pos / BOARD_COLS;
        col = pos % BOARD_COLS;
    }

public:
    Memorama() {
        srand(time(NULL));
        score = 0;
        shuffleBoard();
    }

    void playGame() {
        int pairsFound = 0;
        char input1, input2;

        displayHeader();

        while (pairsFound < TOTAL_PAIRS) {
            displayBoard();
            cout << "\nScore: " << score;

            cout << "\n\nChoose first card (A - L): ";
            cin >> input1;

            if (!isValidLetter(input1)) {
                cout << "Invalid input. Try again.\n";
                continue;
            }

            int x1, y1;
            getCoordinatesFromChar(input1, x1, y1);
            if (board[x1][y1].revealed) {
                cout << "Card already revealed.\n";
                continue;
            }

            board[x1][y1].revealed = true;
            displayBoard();

            cout << "\nChoose second card (A - L): ";
            cin >> input2;

            if (!isValidLetter(input2)) {
                board[x1][y1].revealed = false;
                cout << "Invalid input.\n";
                continue;
            }

            int x2, y2;
            getCoordinatesFromChar(input2, x2, y2);

            if ((x1 == x2 && y1 == y2) || board[x2][y2].revealed) {
                board[x1][y1].revealed = false;
                cout << "Invalid selection.\n";
                continue;
            }

            board[x2][y2].revealed = true;
            displayBoard();

            if (strcmp(board[x1][y1].word, board[x2][y2].word) == 0) {
                cout << "\nNice! You found a match!";
                score += 10;
                pairsFound++;
            } else {
                cout << "\nOops! Not a match.";
                score -= 2;
                board[x1][y1].revealed = false;
                board[x2][y2].revealed = false;
            }

            waitForEnter();
            displayHeader();
        }

        cout << "\n CONGRATULATIONS! You completed the mission!";
        cout << "\n Final Score: " << score << "\n";

    }

    int getScore() {
        return score;
    }
};

#endif
