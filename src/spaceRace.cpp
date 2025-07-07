#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits> // Para numeric_limits

#include "spaceRace.h" // Incluye el archivo de encabezado de esta misión
#include "utils.h"     // Incluye las utilidades compartidas

using namespace std;

const int TRACK_LEN = 30;   // longitud de la pista

// dibuja una linea de carrera para una nave
void drawLine(int pos, string icon) {
    for (int i = 0; i < TRACK_LEN; ++i) {
        if (i == pos)
            cout << icon;      // nave
        else if (i == TRACK_LEN - 1)
            cout << "|";       // meta
        else
            cout << " ";
    }
    cout << "\n";
}

// Función principal de la carrera espacial (Misión 1 de PSR)
void spaceRace () {
    system("cls");
    cout << "Noctriz has arrived at PSR, but the connection with Algoritmia has been lost.\n"; // Introducción a la misión
    cout << "To reestablish it, you must win a spaceship race against an AI prototype.\n"; // Continuación de la introducción
    cout << "Speed and luck will decide if you can send the rescue signal!\n\n"; // Advertencia
    waitForEnter();

    srand(static_cast<unsigned>(time(nullptr))); // línea para poder generar números aleatorios

    int playerPos = 0; // posición inicial del jugador
    int cpuPos    = 0; // posición inicial de la IA
    string input;

    system("cls");
    cout << "=== MISSION PSR: CONNECTION REESTABLISHMENT ===\n"; // Título de la misión en inglés
    cout << "Current Score: " << globalScore << "\n\n"; // Puntaje actual en inglés
    cout << "Spaceship Race!\n" // Título de la carrera
         << "Press Enter to advance, type \"Q\" to quit the race.\n\n"; // Instrucciones en inglés
    waitForEnter(); // Pausa antes de empezar la carrera

    while (playerPos < TRACK_LEN - 1 && cpuPos < TRACK_LEN - 1) {
        system("cls"); // Limpia pantalla para "animar"
        cout << "=== MISSION PSR: CONNECTION REESTABLISHMENT ===\n"; // Título de la misión en inglés
        cout << "Current Score: " << globalScore << "\n\n"; // Puntaje actual en inglés

        // Mostrar pista
        drawLine(playerPos, "}==}>");   // nave del jugador
        drawLine(cpuPos,    ">-o->");   // nave IA
        cout << "\n";

        // Turno del jugador
        cout << "Your turn: "; // Solicitud de entrada en inglés
        getline(cin, input);
        if (input[0] == 'q' || input[0] == 'Q') {
            cout << "\nYou decided to surrender. The connection will not be reestablished for now.\n"; // Mensaje de rendición en inglés
            globalScore -= 100; // Penalización por rendirse
            waitForEnter();
            return; // Sale de la función
        }
        playerPos += (rand() % 2) + 1; // jugador avanza 1-2 elegido aleatoriamente

        // turno de la CPU
        cpuPos += (rand() % 2) + 1; // IA avanza 1‑2 elegido aleatoriamente
    }

    system("cls");
    cout << "=======================================\n";
    cout << "   MISSION PSR: CONNECTION REESTABLISHMENT\n"; // Título de la misión en inglés
    cout << "=======================================\n\n";

    // resultado
    if (playerPos >= TRACK_LEN - 1 && cpuPos >= TRACK_LEN - 1) {
        cout << "It's a tie! The signal is weak but something happened.\n"; // Mensaje de empate en inglés
        globalScore += 50; // Puntos por empate
    } else if (playerPos >= TRACK_LEN - 1) {
        cout << "You won the race! The signal has been successfully sent!\n"; // Mensaje de victoria en inglés
        cout << "Algoritmia has received your message. Well done, Noctriz!\n"; // Mensaje de victoria en inglés
        globalScore += 250; // Bonificación por ganar
    } else {
        cout << "The AI won the race! The connection is still cut.\n"; // Mensaje de derrota en inglés
        cout << "Noctriz could not send the signal. We must find another way!\n"; // Mensaje de derrota en inglés
        globalScore -= 150; // Penalización por perder
    }
    cout << "Mission Score: " << globalScore << "\n"; // Puntaje de la misión
    waitForEnter();
}
