#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>

using namespace std;

// lista de las palabras aleatorias//
string words[] = {"star", "planet", "wifi", "internet", "rocket", "help", "rescue", "galaxy", "travel", "space"};

// funcion para limpiar la pantalla//
void Cleanscreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// dibujo del cuerpo//
void body(int life) {
    switch (life) {
        case 6:
            cout << ".........." << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;

        case 5:
            cout << ".........." << endl;
            cout << "|        O" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;

        case 4:
            cout << ".........." << endl;
            cout << "|        O" << endl;
            cout << "|        |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;

        case 3:
            cout << ".........." << endl;
            cout << "|        O" << endl;
            cout << "|       /|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;

        case 2:
            cout << ".........." << endl;
            cout << "|        O" << endl;
            cout << "|       /|\\" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;

        case 1:
            cout << ".........." << endl;
            cout << "|        O" << endl;
            cout << "|       /|\\" << endl;
            cout << "|       /" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;

        case 0:
            cout << ".........." << endl;
            cout << "|        O" << endl;
            cout << "|       /|\\" << endl;
            cout << "|       / \\" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
    }
}

// juego//
void Playgame() {
    srand(time(0));
    int nA = rand() % 10;

    string word = words[nA];
    string hiddendword(word.length(), '_');

    int life = 6;
    char letter;
    bool win = false;
    string usedletters;

    while (life > 0 && !win) {
        Cleanscreen();
        body(life);

        cout << "Word: " << hiddendword << endl;
        cout << "Remaining lives: " << life << endl;
        cout << "Used letters: " << usedletters << endl;

        string input;
        cout << "Enter a letter: ";
        cin >> input;

        // Validar que solo se ingrese una letra//
        if (input.length() != 1 || !isalpha(input[0])) {
            cout << "Just one letter per try" << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }

        // Convertir a minúscula y que no genere un error//
        letter = tolower(input[0]);

        // Verificar si ya se usó
        if (usedletters.find(letter) != string::npos) {
            cout << "You already tried that letter!" << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }

        usedletters += letter;

        bool hitit = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter && hiddendword[i] == '_') {
                hiddendword[i] = letter;
                hitit = true;
            }
        }

        if (!hitit) {
            life--;
            cout << "Wrong letter, try with another one" << endl;
            cout << "You lose a life... sorry" << endl;
        } else {
            cout << "GOOD!!! It's the correct letter" << endl;
        }

        cout << "Press Enter to continue";
        cin.ignore();
        cin.get();

        if (hiddendword == word) {
            win = true;
        }
    }

    Cleanscreen();
    body(life);
    if (win) {
        cout << "YOU WON! The word was: " << word << endl;
    } else {
        cout << "GAME OVER. The word was: " << word << endl;
    }

    cout << "Press Enter to go back to menu...";
    cin.ignore();
    cin.get();
}

// menú principal//
void mostrarMenu() {
    int options;

    do {
        int life = 6;
        Cleanscreen();

        cout << "----------------------" << endl;
        cout << "       HANGMAN        " << endl;
        cout << "----------------------" << endl;
        cout << "1. PLAY GAME" << endl;
        cout << "2. GO BACK" << endl;
        cin >> options;

        if (options != 1 && options != 2) {
            cout << "THERE IS A PROBLEM... choose between option 1 and 2" << endl;
            cout << "Please try again" << endl;
        } else {
            switch (options) {
                case 1:
                    Playgame();
                    break;
                case 2:
                    cout << "You went back to the principal menu" << endl;
                    break;
            }
        }

    } while (options != 2);
}

#endif