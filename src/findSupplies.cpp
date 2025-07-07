#include <iostream>
#include <conio.h>    // _getch(), códigos de flecha
#include <cstdlib>    // system("cls")
#include <limits>     // Para numeric_limits

#include "findSupplies.h" // Incluye el archivo de encabezado de esta misión
#include "utils.h"        // Incluye las utilidades compartidas

using namespace std;

/* ---------- Laberinto 10 × 10 ---------- */
char maze[10][10] = {
    {'N', '.', '#', '.', '.', 'S', '#', '.', '.', '.'},
    {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.'},
    {'.', '.', '.', '.', '#', '.', '.', '.', '#', 'S'},
    {'#', '#', '#', '.', '#', '#', '#', '.', '#', '.'},
    {'S', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '#', '.'},
    {'.', '.', '.', '.', '#', 'S', '.', '.', '.', '.'},
    {'.', '#', '#', '.', '#', '#', '#', '#', '.', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', 'S', '#', '#', '#', '#', '#', '#', '#', 'S'}
};

// ---------- Inicializar valores para el estado del juego ---------- //
int playerRow = 0, playerCol = 0; // posición de N de Noctriz nuestro protagonista (empezar en posicion 0,0)
int supplies   = 6;               // S restantes (son la cantidad de provisiones dispersadas por el mapa)
int lives      = 6;               // vidas (cantidad de choques máximos con los asteroides "#")

// ---------- Imprimimos el mapa y los datos de vida y provisiones ---------- //
void printMaze()
{
    system("cls");                // limpiar pantalla (Windows)
    cout << "=== MISSION KEPLER-45: SUPPLIES RECOVERY ===\n"; // Título de la misión
    cout << "Current Score: " << globalScore << "\n\n"; // Puntaje actual

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << maze[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\nSupplies left: " << supplies // Suministros restantes
         << "    Lives: "      << lives  << "\n"; // Vidas restantes
    cout << "Use arrow keys to move. Avoid asteroids (#) and collect supplies (S).\n"; // Instrucciones
}

// Asegurarnos de siempre estar dentro del mapa y no atravesar sus límites
bool inside(int r, int c)
{
    return r >= 0 && r < 10 && c >= 0 && c < 10;
}

// ---------- Juego principal de búsqueda de suministros (Misión 2 de Kepler-45) ---------- //
void findSupplies()
{
    system("cls");
    cout << "Alert, Noctriz! The ship has suffered mechanical failures after the last mission.\n"; // Introducción a la misión
    cout << "We cannot return to Algoritmia without repairs. We need to find supplies\n"; // Continuación de la introducción
    cout << "scattered across this asteroid to continue. Be careful with asteroid fields!\n\n"; // Advertencia
    waitForEnter();

    printMaze();

    while (lives > 0 && supplies > 0)
    {
        int key = _getch(); // Lee la tecla presionada

        /* Las flechas llegan como 224 (o 0) + código */
        if (key == 224 || key == 0)
            key = _getch(); // Lee el código real de la flecha

        int nextR = playerRow;
        int nextC = playerCol;

        if (key == 72)       nextR--;        // ↑
        else if (key == 80)  nextR++;        // ↓
        else if (key == 75)  nextC--;        // ←
        else if (key == 77)  nextC++;        // →

        /* Ignorar otras teclas que no sean flechas */
        if (nextR == playerRow && nextC == playerCol)
            continue;

        if (!inside(nextR, nextC)) {
            cout << "You cannot leave the search area, Noctriz!\n"; // Mensaje de fuera de límites
            waitForEnter(); // Pausa para que el jugador vea el mensaje
            printMaze(); // Vuelve a imprimir el laberinto
            continue; // Fuera de límites
        }

        char target = maze[nextR][nextC];

        if (target == '#') {                 // choque con asteroide
            lives--;
            globalScore -= 50; // Restar puntos por chocar
            cout << "Asteroid collision! Lives remaining: " << lives << "\n"; // Mensaje de choque
            waitForEnter();
        } else {
            /* mover la nave */
            if (target == 'S') {
                supplies--;   // recoge provisión
                globalScore += 75; // Sumar puntos por recoger suministro
                cout << "Supply collected! Remaining: " << supplies << "\n"; // Mensaje de suministro recogido
                waitForEnter();
            }

            maze[playerRow][playerCol] = '.'; // deja espacio en la posición anterior
            playerRow = nextR;
            playerCol = nextC;
            maze[playerRow][playerCol] = 'N'; // Mueve a Noctriz a la nueva posición
        }

        printMaze();
    }

    system("cls");
    cout << "=======================================\n";
    cout << "   MISSION KEPLER-45: SUPPLIES RECOVERY\n";
    cout << "=======================================\n\n";

    if (supplies == 0) {
        cout << "Mission accomplished! You've obtained enough supplies to repair the ship.\n"; // Misión cumplida
        cout << "Noctriz can continue his journey. Algoritmia awaits you!\n"; // Continuación de la victoria
        globalScore += 200; // Bonificación por éxito
    } else {
        cout << "Out of fuel... Noctriz's ship is stranded.\n"; // Combustible agotado
        cout << "Too many asteroid collisions. Mission failed.\n"; // Misión fallida
        globalScore -= 150; // Penalización por fracaso
    }
    cout << "Mission Score: " << globalScore << "\n"; // Puntaje de la misión
    waitForEnter();
}