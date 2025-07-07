#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype> // para tolower()
#include <limits> // Para numeric_limits

#include "guessPassword.h" // Incluye el archivo de encabezado de esta misión
#include "utils.h"         // Incluye las utilidades compartidas

using namespace std;

// Variables globales del juego del ahorcado (definidas aquí, no en el .h)
string word; // palabra que se va a adivinar y funcionará como contraseña
string guessedLetters = ""; // lista que almacena las letras intentadas

// dibujo del cuerpo del ahorcado
void body(int lives) {
    cout << " ________" << endl;
    cout << " |      |" << endl;
    if (lives < 6) cout << " |      O" << endl; else cout << " |" << endl;
    if (lives < 4) cout << " |     /|\\ " << endl; else if (lives < 5) cout << " |      |" << endl; else cout << " |" << endl;
    if (lives < 2) cout << " |     / \\" << endl; else if (lives < 3) cout << " |     / " << endl; else cout << " |" << endl;
    cout << " |" << endl;
    cout << "_|_ " << endl;
}

void showProgress() {
    cout << "\nWord: "; // Etiqueta de la palabra en inglés
    for (char c : word) {
        if (guessedLetters.find(c) != string::npos) // npos significa no-position
            cout << c << " ";  // letra ya adivinada
        else
            cout << "_ ";      // letra aún no adivinada
    }
    cout << endl;
}

// Se descubre la contraseña por medio de un juego de ahorcados (Misión 2 de PSR)
void guessPassword() {
    system("cls");
    cout << "Noctriz has received information about the AI's secret base.\n"; // Introducción a la misión
    cout << "To infiltrate, you must decrypt the password. The AI's henchmen have left clues...\n"; // Continuación de la introducción
    cout << "Every letter is an opportunity to get closer to victory!\n\n"; // Advertencia
    waitForEnter();

    srand(static_cast<unsigned>(time(nullptr)));

    string words[] = {"star", "planet", "wifi", "internet", "rocket", "help", "rescue", "galaxy", "travel", "space", "algorithm", "logic", "binary", "code", "system"}; // Palabras en inglés
    int choose = rand() % (sizeof(words) / sizeof(words[0])); // Asegura que el índice esté dentro del rango
    word = words[choose];

    guessedLetters = "";
    int lives = 6; // Vidas del ahorcado

    while (lives > 0) {
        system("cls"); // Limpiar pantalla
        cout << "=== MISSION PSR: DECRYPTING THE PASSWORD ===\n"; // Título de la misión en inglés
        cout << "Current Score: " << globalScore << "\n"; // Puntaje actual en inglés
        cout << "Lives remaining: " << lives << endl; // Vidas restantes en inglés
        body(lives);
        cout << "----------------------------------\n";
        showProgress();
        cout << "Guessed letters: " << guessedLetters << "\n"; // Letras intentadas en inglés

        // Entrada de letra
        string input;
        while (true) {
            cout << "\nType a letter to try, or press Enter to quit: "; // Solicitud de entrada en inglés
            getline(cin, input);

            // Salir si solo presionó Enter
            if (input.empty()) {
                cout << "\nYou decided to surrender. The AI's password remains hidden.\n"; // Mensaje de rendición en inglés
                globalScore -= 100; // Penalización por rendirse
                waitForEnter();
                return; // Sale de la función
            }

            // Validar que sea una sola letra
            if (input.length() != 1) {
                cout << "Error: Please enter only one character.\n";
                continue;
            }

            // Validar que sea una letra del alfabeto
            char ch = input[0];
            if (!isalpha(ch)) {
                cout << "Error: Only letters A-Z are allowed.\n";
                continue;
            }

            // Si pasa las validaciones, salir del bucle
            break;
        }

        char letter = tolower(input[0]);

        if (!isalpha(letter)) { // Verifica si es una letra del alfabeto
            cout << "Invalid input! Please enter only letters.\n"; // Mensaje de error en inglés
            waitForEnter();
            continue;
        }

        if (guessedLetters.find(letter) != string::npos) {
            cout << "You already tried the letter '" << letter << "'.\n"; // Mensaje de letra ya intentada en inglés
            waitForEnter();
            continue;
        }

        guessedLetters += letter;

        // Verificar si la letra está en la palabra
        if (word.find(letter) == string::npos) {
            cout << "Incorrect guess!\n"; // Mensaje de intento incorrecto en inglés
            lives--;  // solo se descuenta si falló
            globalScore -= 20; // Restar puntos por intento fallido
        } else {
            cout << "Correct guess!\n"; // Mensaje de intento correcto en inglés
            globalScore += 30; // Sumar puntos por letra correcta
        }

        // Comprobar si ya ganó
        bool won = true;
        for (char c : word) {
            if (guessedLetters.find(c) == string::npos) {
                won = false;
                break;
            }
        }

        if (won) {
            system("cls");
            cout << "=== MISSION PSR: DECRYPTING THE PASSWORD ===\n"; // Título de la misión en inglés
            cout << "Current Score: " << globalScore << "\n"; // Puntaje actual en inglés
            showProgress();
            cout << "\nCONGRATULATIONS! You deciphered the password: " << word << "\n"; // Mensaje de victoria en inglés
            cout << "The AI's base is open! Noctriz can enter and confront it.\n"; // Mensaje de victoria en inglés
            globalScore += 300; // Bonificación por ganar
            break;
        }
        waitForEnter();
    }

    system("cls");
    cout << "=======================================\n";
    cout << "   MISSION PSR: DECRYPTING THE PASSWORD\n"; // Título de la misión en inglés
    cout << "=======================================\n\n";

    if (lives < 1) {
        cout << "You ran out of lives! The password was: " << word << "\n"; // Mensaje de derrota en inglés
        cout << "The AI has kept its secret. Mission failed.\n"; // Mensaje de derrota en inglés
        globalScore -= 200; // Penalización por perder
    }
    cout << "Mission Score: " << globalScore << "\n"; // Puntaje de la misión
    waitForEnter();
}
