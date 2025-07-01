#ifndef MEMORAMA_H
#define MEMORAMA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

const int BOARD_ROWS = 3;
const int BOARD_COLS = 3;
const int TOTAL_CARDS = BOARD_ROWS * BOARD_COLS;
const int TOTAL_PAIRS = 4; // 4 pares = 8 cartas normales
const char BONUS_WORD[] = "BONUS";

struct Card {
    char word[20];
    bool revealed;
    bool isBonus;
};

class Memorama {
private:
    Card board[BOARD_ROWS][BOARD_COLS];
    char words[TOTAL_PAIRS][20] = {
        "AI", "Logic", "Data", "Neuron"
    };
    int score;

    void shuffleBoard() {
        char tempWords[TOTAL_CARDS][20];
        int index = 0;

        // Agregar pares normales (duplicados)
        for (int i = 0; i < TOTAL_PAIRS; ++i) {
            strcpy(tempWords[index++], words[i]);
            strcpy(tempWords[index++], words[i]);
        }

        // Agregar carta BONUS
        strcpy(tempWords[index++], BONUS_WORD);

        // Rellenar board temporalmente
        for (int i = 0; i < TOTAL_CARDS; ++i) {
            int r = rand() % TOTAL_CARDS;
            char temp[20];
            strcpy(temp, tempWords[i]);
            strcpy(tempWords[i], tempWords[r]);
            strcpy(tempWords[r], temp);
        }

        index = 0;
        for (int i = 0; i < BOARD_ROWS; ++i) {
            for (int j = 0; j < BOARD_COLS; ++j) {
                strcpy(board[i][j].word, tempWords[index]);
                board[i][j].revealed = false;
                board[i][j].isBonus = strcmp(tempWords[index], BONUS_WORD) == 0;
                index++;
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
        return (input >= 'A' && input < 'A' + TOTAL_CARDS);
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
        bool bonusClaimed = false;
        char input1, input2;

        displayHeader();

        while (pairsFound < TOTAL_PAIRS) {
            displayBoard();
            cout << "\nScore: " << score;

            cout << "\n\nChoose first card (A - I): ";
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

            // Si es carta bonus
            if (board[x1][y1].isBonus && !bonusClaimed) {
                cout << "\nBONUS FOUND! +10 points!";
                score += 10;
                bonusClaimed = true;
                waitForEnter();
                displayHeader();
                continue;
            }

            displayBoard();
            cout << "\nChoose second card (A - I): ";
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

            // Si segunda es BONUS, se cancela
            if (board[x2][y2].isBonus) {
                cout << "\nOops! That's a BONUS card, only one can be flipped at a time.";
                board[x1][y1].revealed = false;
                board[x2][y2].revealed = false;
                waitForEnter();
                displayHeader();
                continue;
            }

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

        cout << "\nCONGRATULATIONS! You completed the mission!";
        cout << "\nFinal Score: " << score << "\n";
    }

    int getScore() {
        return score;
    }
};

#endif
