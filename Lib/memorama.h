#ifndef MEMORAMA_H
#define MEMORAMA_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

const int BOARD_SIZE = 4; // 4x4 tablero, 8 pares
const int TOTAL_PAIRS = BOARD_SIZE * BOARD_SIZE / 2;

struct Card {
    char word[20];
    bool discovered;
};

class Memorama {
private:
    Card board[BOARD_SIZE][BOARD_SIZE];
    char words[TOTAL_PAIRS][20] = {
        "IA", "Algoritmo", "Red", "Datos",
        "Machine", "Aprendizaje", "Neuronas", "Modelo"
    };
    int score;

    void shuffleWords() {
        char tempWords[BOARD_SIZE * BOARD_SIZE][20];
        int index = 0;

        // Copiar cada palabra dos veces
        for (int i = 0; i < TOTAL_PAIRS; ++i) {
            strcpy(tempWords[index++], words[i]);
            strcpy(tempWords[index++], words[i]);
        }

        // Mezclar
        for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
            int r = rand() % (BOARD_SIZE * BOARD_SIZE);
            char temp[20];
            strcpy(temp, tempWords[i]);
            strcpy(tempWords[i], tempWords[r]);
            strcpy(tempWords[r], temp);
        }

        // Colocar en el tablero
        index = 0;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                strcpy(board[i][j].word, tempWords[index++]);
                board[i][j].discovered = false;
            }
        }
    }

    void showBoard(bool revealAll = false) {
        std::cout << "\n";
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j].discovered || revealAll) {
                    std::cout << board[i][j].word << "\t";
                } else {
                    std::cout << "[" << i << "," << j << "]\t";
                }
            }
            std::cout << "\n";
        }
    }

public:
    Memorama() {
        srand(time(NULL));
        score = 0;
        shuffleWords();
    }

    void playGame() {
        int pairsFound = 0;
        while (pairsFound < TOTAL_PAIRS) {
            showBoard();

            int x1, y1, x2, y2;
            std::cout << "\nElige la primera carta (fila columna): ";
            std::cin >> x1 >> y1;

            std::cout << "Elige la segunda carta (fila columna): ";
            std::cin >> x2 >> y2;

            if (x1 == x2 && y1 == y2) {
                std::cout << "No puedes elegir la misma carta dos veces.\n";
                continue;
            }

            if (board[x1][y1].discovered || board[x2][y2].discovered) {
                std::cout << "Ya descubriste alguna de esas cartas.\n";
                continue;
            }

            std::cout << "\nCarta 1: " << board[x1][y1].word;
            std::cout << "\nCarta 2: " << board[x2][y2].word << "\n";

            if (strcmp(board[x1][y1].word, board[x2][y2].word) == 0) {
                std::cout << "¡Correcto! Encontraste un par.\n";
                board[x1][y1].discovered = true;
                board[x2][y2].discovered = true;
                score += 10;
                pairsFound++;
            } else {
                std::cout << "No coinciden. Intenta otra vez.\n";
                score -= 2;
            }

            std::cout << "Puntaje actual: " << score << "\n";
        }

        std::cout << "\n¡Felicidades! Completaste el memorama. Puntaje final: " << score << "\n";
    }

    int getScore() {
        return score;
    }
};

#endif
