#include <iostream>     // Para entrada/salida por consola
#include <cstdlib>      // Para rand(), srand()
#include <ctime>        // Para time() (semilla aleatoria)
#include <string>       // Para usar strings
#include <limits>       // Para limpiar el buffer del cin si se necesita

#include "searchInfo.h" // Archivo de encabezado propio del juego (declaraciones externas)
#include "utils.h"      // Utilidades auxiliares como waitForEnter()

using namespace std;

// === VARIABLES GLOBALES DEL JUEGO ===
int board[4][4];         // Tablero de 4x4 con 8 parejas (16 posiciones)
bool revealed[4][4];     // Marca qué cartas están reveladas
string aiInfo[8] = {     // Información revelada al encontrar cada pareja
    "Its core is hidden in an asteroid near Kepler-45.",
    "It controls drones that look like meteors.",
    "The AI was accidentally created during a failed experiment.",
    "Noctriz can block it using pure C++ code.",
    "Its weakness lies in complex logical patterns.",
    "It feeds on disorganization and digital chaos.",
    "An ancient encryption algorithm can override its defenses.",
    "Its secret base is protected by an 8-letter password."
};

int pairsFound = 0; // Contador de parejas encontradas

// === INICIALIZAR EL JUEGO ===
void initializeGame() {
    int values[16]; // Arreglo temporal con los valores a colocar en el tablero (8 parejas)

    // Rellenar el arreglo con 8 parejas (dos de cada número del 1 al 8)
    for (int i = 0; i < 8; ++i) {
        values[i * 2] = i + 1;
        values[i * 2 + 1] = i + 1;
    }

    // Mezclar los valores aleatoriamente usando Fisher-Yates
    srand(time(0)); // Semilla aleatoria basada en el tiempo actual
    for (int i = 0; i < 16; i++) {
        int pos = rand() % 16;
        int temp = values[i];
        values[i] = values[pos];
        values[pos] = temp;
    }

    // Asignar valores mezclados al tablero y marcar todas las cartas como ocultas
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = values[index];
            revealed[i][j] = false;
            index++;
        }
    }
}

// === MOSTRAR EL TABLERO EN PANTALLA ===
void showBoard() {
    system("cls"); // Limpia la pantalla (solo funciona en Windows)
    cout << "=== MISSION KEPLER-45: AI DATA SEARCH ===\n";
    cout << "Agent Noctriz | Pairs Found: " << pairsFound << "/8\n";
    cout << "Current Score: " << globalScore << "\n\n";

    // Imprimir encabezado de columnas
    cout << "   1   2   3   4\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << "  "; // Número de fila
        for (int j = 0; j < 4; j++) {
            if (revealed[i][j]) {
                cout << board[i][j] << "   "; // Mostrar número si está revelado
            } else {
                cout << "[]  "; // Mostrar carta oculta
            }
        }
        cout << "\n";
    }
}

// === FUNCIÓN PRINCIPAL DEL JUEGO ===
void play() {
    system("cls"); // Limpiar pantalla
    cout << "Noctriz has arrived at Kepler-45. This planet holds the key to understanding the AI.\n";
    cout << "You must find pairs of data to unlock vital information about the enemy.\n";
    cout << "Concentrate, every piece of information is crucial!\n\n";
    waitForEnter(); // Esperar que el jugador presione Enter

    initializeGame(); // Preparar tablero y estado inicial
    pairsFound = 0;   // Reiniciar contador de parejas

    // Bucle principal del juego
    while (pairsFound < 8) {
        showBoard(); // Mostrar el estado actual del tablero

        int row1, col1, row2, col2; // Coordenadas de las cartas elegidas
        string input; // Entrada del usuario (como string para validarla)

        // === PRIMERA CARTA ===
        while (true) {
            cout << "\nFirst card - Row (1-4): ";
            cin >> input;

            // Validar que sea un dígito entre 1 y 4
            if (input.length() != 1 || !isdigit(input[0])) {
                cout << "Invalid input. Enter a number from 1 to 4.\n";
                continue;
            }

            row1 = input[0] - '0'; // Convertir a número
            if (row1 < 1 || row1 > 4) {
                cout << "Row must be between 1 and 4.\n";
                continue;
            }

            row1--; // Ajustar a índice base 0

            // Verificar que haya cartas ocultas en esa fila
            bool available = false;
            for (int j = 0; j < 4; j++) {
                if (!revealed[row1][j]) {
                    available = true;
                    break;
                }
            }

            if (!available) {
                cout << "All cards in this row are already revealed. Choose another row.\n";
                continue;
            }

            break; // Entrada válida
        }

        // Columna de la primera carta
        while (true) {
            cout << "Column (1-4): ";
            cin >> input;

            if (input.length() != 1 || !isdigit(input[0])) {
                cout << "Invalid input. Enter a number from 1 to 4.\n";
                continue;
            }

            col1 = input[0] - '0';
            if (col1 < 1 || col1 > 4) {
                cout << "Column must be between 1 and 4.\n";
                continue;
            }

            col1--;

            if (revealed[row1][col1]) {
                cout << "Card already revealed. Choose another.\n";
                continue;
            }

            break;
        }

        // === SEGUNDA CARTA ===
        while (true) {
            cout << "Second card - Row (1-4): ";
            cin >> input;

            if (input.length() != 1 || !isdigit(input[0])) {
                cout << "Invalid input. Enter a number from 1 to 4.\n";
                continue;
            }

            row2 = input[0] - '0';
            if (row2 < 1 || row2 > 4) {
                cout << "Row must be between 1 and 4.\n";
                continue;
            }

            row2--;

            bool available = false;
            for (int j = 0; j < 4; j++) {
                if (!revealed[row2][j]) {
                    available = true;
                    break;
                }
            }

            if (!available) {
                cout << "All cards in this row are already revealed. Choose another row.\n";
                continue;
            }

            break;
        }

        // Columna de la segunda carta
        while (true) {
            cout << "Column (1-4): ";
            cin >> input;

            if (input.length() != 1 || !isdigit(input[0])) {
                cout << "Invalid input. Enter a number from 1 to 4.\n";
                continue;
            }

            col2 = input[0] - '0';
            if (col2 < 1 || col2 > 4) {
                cout << "Column must be between 1 and 4.\n";
                continue;
            }

            col2--;

            if (revealed[row2][col2]) {
                cout << "Card already revealed. Choose another.\n";
                continue;
            }

            if (row1 == row2 && col1 == col2) {
                cout << "Cannot choose the same card twice. Try again.\n";
                continue;
            }

            break;
        }

        // === MOSTRAR TEMPORALMENTE LAS DOS CARTAS SELECCIONADAS ===
        system("cls");
        cout << "=== MISSION KEPLER-45: AI DATA SEARCH ===\n";
        cout << "Agent Noctriz | Pairs Found: " << pairsFound << "/8\n";
        cout << "Current Score: " << globalScore << "\n\n";
        cout << "   1   2   3   4\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << "  ";
            for (int j = 0; j < 4; j++) {
                if ((i == row1 && j == col1) || (i == row2 && j == col2) || revealed[i][j]) {
                    cout << board[i][j] << "   "; // Mostrar carta si está revelada o es seleccionada
                } else {
                    cout << "[]  ";
                }
            }
            cout << "\n";
        }

        // Mostrar números seleccionados
        cout << "\nCard 1: " << board[row1][col1];
        cout << " | Card 2: " << board[row2][col2] << "\n";

        // === VERIFICAR SI HAY PAREJA ===
        if (board[row1][col1] == board[row2][col2]) {
            cout << "\nPAIR FOUND! Excellent work, Noctriz!\n";
            revealed[row1][col1] = true;
            revealed[row2][col2] = true;
            pairsFound++;
            globalScore += 100; // Recompensa

            // Mostrar fragmento de información
            cout << "DATA #" << pairsFound << ": " << aiInfo[board[row1][col1] - 1] << "\n";
            waitForEnter();
        } else {
            cout << "\nNot a match. Keep trying!\n";
            globalScore -= 25; // Penalización
            waitForEnter();
        }
    }

    // === FIN DEL JUEGO ===
    system("cls");
    cout << "=======================================\n";
    cout << "       MISSION KEPLER-45: AI DATA\n";
    cout << "=======================================\n\n";
    cout << "MISSION COMPLETE!\n";
    cout << "Noctriz has obtained key information about the AI:\n\n";
    for (int i = 0; i < 8; i++) {
        cout << (i + 1) << ". " << aiInfo[i] << "\n";
    }
    cout << "\nData successfully transmitted to Algoritmia! Now we know more about the enemy.\n";
    cout << "Mission Score: " << globalScore << "\n";
    waitForEnter(); // Esperar antes de salir
}
