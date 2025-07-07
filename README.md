[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)

# Proyecto de C++ - OWL ROCKET 🚀

## 👨‍🚀 Team

- **Team name:** Asteroides con WiFi
- **Game Name:** OWL ROCKET

| Name   | ID|
|--------|--------|
| Leila Saraí Campos Peraza | 00141525 |
| Rubén Eliseo Martínez Perez | 00076325 |
| Álvaro David Campos Jimenez | 00135525 |
| Keiryn Lisette Diaz Cartagena | 00061225 |
| Christian Alexis Martinez Moran | 00053325 |

---

## 🧠 Theme and setting

 You need to go with **Noctriz** in a space adventure full of missions to save all the population of  **Algoritmia**, they have been kidnapped by an AI.This game implies logic in different ways ,memory and chanllenges across the intersllestar space. 

---

## 🎮  Principal Game Mechanic 

The player will face different  **missions** in different planets:

- Solve logic puzzles.
- Find supplies(memogram).
- Find passwords.
- Participate in a space career.

Each mission corresponds to a module of the program and allows access to an interactive menu.
This menu lets the player choose the planet they would like to start with, which will be their first destination.
---

## 🕹️ General gameplay idea 

1. The player starts with Noctriz, astronaut of Algoritmia.

2. The player can choose between differents missions in the pincipal menu. 

3. Each mission in every minigame has its own logic and mechanics.

4. Each dessicion and it's results will appear at the console.

5. After completing all the missions, the player frees Algoritmia from the AI.

---

## 💻 Applying the concepts learned

| **Course Topics**                  | **AGame Application**                                                                 |
|-----------------------------------|----------------------------------------------------------------------------------------|
| **Variables and Data Types**      | Uses `int`, `float`, `bool`, and `string` to control gameplay elements in missions.   |
| **Conditional Structures**        | Implements `if`, `else`, and `switch` to allow player decisions that impact the game's flow and outcomes. |
| **Loops (`for`, `while`, `do-while`)** | Used for repeating attempts, validating input, and creating interactive mission logic.  |
| **Functions**                     | Missions and utility features are organized into modular functions (e.g., `startMission1()`, `checkProgress()`). |
| **Data Structures**               | Arrays like `string[]` and `int[]` are used to manage data in mini-games.              |
| **File Handling**                 | Game scores and progress are saved using `fstream`.                                   |
| **Error Handling**                | Validates user input to prevent crashes and ensure a smooth user experience.           |
| **Console Interface**             | Uses `cout`, `cin`, separators, and ASCII art to build interactive and visually appealing menus. |


## 🛠️Technical Considerations of Development

- Lenguage: C++
- Used IDE : Visual Studio Code
- Repository shared in GitHub
- Modularization: Each mission is contained in its own`.cpp` and `.h`
- The `main.cpp`  file only includes calls to the primary functions of each mission **OWL ROCKET**.

---

## 🗂️ C++ Documentation

 *This part explains the code and how you can play the videogame called "Owl Rocket".*

 **_Main.cpp_**

 ```cpp
#include <iostream> // Para entrada y salida de datos (cout, cin)
#include <string>   // Para el manejo de cadenas de texto (string)
#include <cstdlib>  // Para funciones de utilidad general, como system("cls") para limpiar la pantalla

/* 
 Incluye los archivos de encabezado de las misiones y utilidades 
 Estos archivos contienen las declaraciones de las funciones que se utilizan en main.cpp 
 para evitar añadir todo el código directamente al main, esto nos permite un código
 mucho más modularizado.
 */
#include "src/utils.h"         // Contiene funciones de utilidad como displayGameIntroduction, displayPlanetSelectionMenu, etc.
#include "src/searchInfo.h"    // Contiene la función play() para la misión de Búsqueda de Información
#include "src/findSupplies.h"  // Contiene la función findSupplies() para la misión de Recuperación de Suministros
#include "src/spaceRace.h"     // Contiene la función spaceRace() para la misión de Restablecimiento de Conexión
#include "src/guessPassword.h" // Contiene la función guessPassword() para la misión de Descifrando Contraseña

/**
 * Función principal del programa.
 *
 * Esta función hace el flujo general del juego "OWl Rocket".
 * Llama a las funciones de introducción, selección de planeta, inicio de misión,
 * manejo de misiones y resumen final.
 *
 * Retorna 0 si el programa finaliza correctamente.
 */
int main() {

    // Muestra la introducción del juego al usuario.
    // Explica la premisa del juego y el rol del agente Noctriz.
    displayGameIntroduction();

    int planetChoice; // Variable para almacenar la elección del planeta por parte del usuario

    // Muestra el menú de selección de planeta y obtiene la elección del usuario.
    // La elección se guarda en la variable planetChoice.
    displayPlanetSelectionMenu(planetChoice);

    // Muestra un mensaje de inicio de misión personalizado basado en el planeta elegido.
    displayMissionStartMessage(planetChoice);

    // Llama a la función que maneja la ejecución de las misiones específicas del planeta elegido.
    // Esta función contiene la lógica para decidir qué misiones ejecutar (Kepler-45 o PSR).
    handlePlanetMissions(planetChoice);

    // Muestra el resumen final del juego, incluyendo la puntuación obtenida por el jugador.
    displayGameSummary();

    return 0; // Indica que el programa se ejecutó sin errores
}
    cpp``` 

   **_src/utils.cpp_**


```cpp

/*
Esta parte es utilizada para tener un código mucho más estructurado,
aquí se encuentran funciones necesarias para el manejo fluido del juego.

*/
#include <iostream> // Para entrada y salida de datos (cout, cin)
#include <limits>   // Para numeric_limits, utilizado para limpiar el buffer de entrada
#include <cstdlib>  // Para system("cls") para limpiar la pantalla
#include <string>   // Para el manejo de cadenas de texto (string)

#include "utils.h"         // Incluye el archivo de encabezado de esta utilidad
#include "searchInfo.h"    // Para la función play()
#include "findSupplies.h"  // Para la función findSupplies()
#include "spaceRace.h"     // Para la función spaceRace()
#include "guessPassword.h" // Para la función guessPassword()

using namespace std; // Usa el espacio de nombres estándar

// Definición de la variable global para la puntuación del juego.
// Esta variable es accesible y modificable desde cualquier parte del programa.
int globalScore = 0;

/**
 *  Espera a que el usuario presione la tecla Enter para continuar.
 *
 * Esta función es útil para pausar la ejecución del programa y permitir al usuario
 * leer mensajes en la consola antes de avanzar.
 */
void waitForEnter() {
    cout << "\nPress Enter to continue..."; // Solicita al usuario que presione Enter
    // Ignora y descarta cualquier carácter restante en el buffer de entrada
    // hasta encontrar un salto de línea, asegurando que futuras entradas no se vean afectadas.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 *   Muestra la introducción del juego al usuario.
 *
 * Limpia la pantalla y presenta la premisa del juego y el rol del agente Noctriz.
 */
void displayGameIntroduction() {
    system("cls"); // Limpia la pantalla de la consola
    cout << "=======================================\n";
    cout << "   WELCOME TO NOCTRIZ: THE ALGORITMIA AGENT\n";
    cout << "=======================================\n\n";
    cout << "In a galaxy far, far away, the planet Algoritmia is threatened by a rogue AI.\n";
    cout << "You are Noctriz, a highly trained agent tasked with a crucial mission:\n";
    cout << "to neutralize the AI and restore peace to the galaxy.\n";
    cout << "Your journey will take you to two mysterious planets: Kepler-45 and PSR.\n";
    cout << "Each one holds unique challenges and vital information.\n\n";
    waitForEnter(); // Espera la confirmación del usuario
}

/**
 *   Muestra el menú de selección de planeta y obtiene la elección del usuario.
 *
 * Solicita al usuario que elija entre Kepler-45 y PSR, validando la entrada.
 *
 *  planetChoice Referencia a un entero donde se almacenará la elección del planeta (1 o 2).
 */
void displayPlanetSelectionMenu(int& planetChoice) {
    system("cls"); // Limpia la pantalla
    cout << "=======================================\n";
    cout << "   SELECT YOUR DESTINATION\n";
    cout << "=======================================\n\n";
    cout << "Where do you want to start your mission, Agent Noctriz?\n";
    cout << "1. Kepler-45 (Information Search & Supplies Recovery)\n";
    cout << "2. PSR (Connection Reestablishment & Password Decryption)\n";
    cout << "\nEnter your choice (1 or 2): ";

    // Bucle para validar la entrada del usuario.
    // Se repetirá hasta que el usuario ingrese 1 o 2.
    while (!(cin >> planetChoice) || (planetChoice != 1 && planetChoice != 2)) {
        cout << "Invalid choice. Please enter 1 for Kepler-45 or 2 for PSR: ";
        cin.clear(); // Limpia cualquier flag de error de cin (ej. si el usuario ingresa texto)
        // Ignora el resto de la línea en el buffer de entrada hasta el salto de línea.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Limpia el buffer después de una entrada válida para evitar problemas con futuras lecturas.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 *   Muestra un mensaje de inicio de misión personalizado.
 *
 * El mensaje varía dependiendo del planeta que el usuario haya elegido.
 *
 *  planetChoice La elección del planeta (1 para Kepler-45, 2 para PSR).
 */
void displayMissionStartMessage(int planetChoice) {
    system("cls"); // Limpia la pantalla
    cout << "=======================================\n";
    cout << "   MISSION BRIEFING\n";
    cout << "=======================================\n\n";
    if (planetChoice == 1) {
        cout << "You've chosen to go to Kepler-45. Your first mission there will be to recover vital information.\n";
        cout << "Be prepared for a challenge of memory and logic!\n";
    } else {
        cout << "You've chosen to go to PSR. Your first mission there will be to reestablish communication with Algoritmia.\n";
        cout << "Prepare for a high-speed challenge!\n";
    }
    waitForEnter(); // Espera la confirmación del usuario
}

/**
 *  Muestra un mensaje indicando que una misión ha sido completada.
 *
 *  Este mensaje se muestra entre misiones en el mismo planeta.
 *
 *  planetChoice La elección del planeta para adaptar el mensaje.
 */
void displayMissionCompleteMessage(int planetChoice) {
    system("cls"); // Limpia la pantalla
    cout << "=======================================\n";
    cout << "   MISSION COMPLETE!\n";
    cout << "=======================================\n\n";
    cout << "You have successfully completed a mission on ";
    if (planetChoice == 1) {
        cout << "Kepler-45.\n";
    } else {
        cout << "PSR.\n";
    }
    cout << "Prepare for the next challenge!\n";
    waitForEnter();
}

/**
 *   Maneja la ejecución de las misiones según el planeta elegido.
 *
 * Esta función es el centro de control de las misiones.
 * Basándose en la elección del planeta, llama a las funciones de las misiones correspondientes.
 * Incluye mensajes intermedios entre misiones para la experiencia del usuario.
 *
 * planetChoice La elección del planeta (1 para Kepler-45, 2 para PSR).
 */
void handlePlanetMissions(int planetChoice) {
    if (planetChoice == 1) {
        // Misiones de Kepler-45
        play(); // Misión 1: Búsqueda de Información (Juego de Memoria)
        displayMissionCompleteMessage(planetChoice); // Mensaje intermedio
        findSupplies(); // Misión 2: Recuperación de Suministros (Juego de Laberinto)
    } else { // planetChoice == 2
        // Misiones de PSR
        spaceRace(); // Misión 1: Restablecimiento de Conexión (Juego de Carrera Espacial)
        displayMissionCompleteMessage(planetChoice); // Mensaje intermedio
        guessPassword(); // Misión 2: Descifrando Contraseña (Juego del Ahorcado)
    }
}

/**
 *   Muestra el resumen final del juego.
 *
 * Presenta la puntuación final obtenida por el jugador y un mensaje de despedida.
 */
void displayGameSummary() {
    system("cls"); // Limpia la pantalla
    cout << "=======================================\n";
    cout << "   GAME SUMMARY\n";
    cout << "=======================================\n\n";
    cout << "Your adventure as Agent Noctriz has concluded.\n";
    cout << "You faced numerous challenges and proved your worth!\n\n";
    cout << "Final Score: " << globalScore << " points.\n\n"; // Muestra la puntuación global final
    cout << "Thank you for playing Noctriz: The Algoritmia Agent!\n";
    cout << "See you on your next mission, Agent!\n";
    waitForEnter(); // Espera la confirmación final del usuario antes de que el programa termine
}

**_src/searchInfo_**

```cpp
#include <iostream> // Para entrada y salida de datos (cout, cin)
#include <cstdlib>  // Para funciones de utilidad general como system("cls") y srand
#include <ctime>    // Para la función time(), utilizada en srand para inicializar el generador de números aleatorios
#include <string>   // Para el manejo de cadenas de texto (string)
#include <limits>   // Para numeric_limits, utilizado para limpiar el buffer de entrada

#include "searchInfo.h" // Incluye el archivo de encabezado de esta misión
#include "utils.h"      // Incluye las utilidades compartidas, como globalScore y waitForEnter()

using namespace std; // Usa el espacio de nombres estándar para evitar prefijar cout, cin, etc. con std::

// Tablero de palabras del juego de memoria 3x3
string boardWords[3][3];
// Tablero booleano para controlar qué cartas están reveladas
bool revealed[3][3];
// Contador de pares encontrados por el jugador
int pairsFound = 0;

// Array de palabras base para el juego, incluyendo un "Bonus"
string words[5] = { "Logic", "IA", "Rocket", "Space", "Bonus" };

/**
 * Inicializa el tablero del juego de memoria.
 *
 * Rellena el tablero con pares de palabras aleatoriamente, incluyendo una carta "Bonus".
 * Todas las cartas se inicializan como no reveladas.
 */
void initializeGame() {
    // Array temporal con las palabras que se distribuirán en el tablero.
    // Hay 4 pares de palabras y una palabra "Bonus" singular.
    string values[9] = {
        "Logic", "Logic",
        "IA", "IA",
        "Rocket", "Rocket",
        "Space", "Space",
        "Bonus"
    };

    // Inicializa el generador de números aleatorios con la hora actual.
    // Esto asegura que el orden de las palabras sea diferente en cada ejecución.
    srand(static_cast<unsigned>(time(nullptr)));

    // Mezcla las palabras en el array `values` usando el algoritmo de Fisher-Yates.
    for (int i = 0; i < 9; i++) {
        int pos = rand() % 9; // Elige una posición aleatoria
        string temp = values[i]; // Intercambia la palabra actual con la de la posición aleatoria
        values[i] = values[pos];
        values[pos] = temp;
    }

    // Llena el tablero `boardWords` y el tablero `revealed` con las palabras mezcladas.
    int index = 0; // Índice para recorrer el array `values`
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            boardWords[i][j] = values[index]; // Asigna la palabra al tablero
            revealed[i][j] = false;          // Inicialmente, ninguna carta está revelada
            index++;                         // Pasa a la siguiente palabra
        }
    }
}

/**
 *  Muestra el tablero del juego en la consola.
 *
 * Imprime el tablero, mostrando las cartas reveladas y ocultando las no reveladas con "[ ]".
 */
void showBoard() {
    system("cls"); // Limpia la pantalla
    cout << "=== MISSION KEPLER-45: INFORMATION SEARCH ===\n"; // Título de la misión
    cout << "Current Score: " << globalScore << "\n\n"; // Muestra la puntuación actual

    cout << "  1   2   3\n"; // Encabezados de columna
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " "; // Encabezado de fila
        for (int j = 0; j < 3; j++) {
            if (revealed[i][j]) {
                cout << boardWords[i][j] << " "; // Muestra la palabra si la carta está revelada
            } else {
                cout << "[ ] "; // Muestra "[ ]" si la carta está oculta
            }
        }
        cout << "\n"; // Salto de línea al final de cada fila
    }
    cout << "\n";
}

/**
 *  Obtiene las coordenadas de una carta del usuario.
 *
 * Solicita al usuario la fila y columna de la carta, validando que sean números válidos
 * y que las coordenadas estén dentro del rango del tablero (1-3).
 *
 *  row Referencia a un entero para almacenar la fila elegida.
 *  col Referencia a un entero para almacenar la columna elegida.
 */
void getCardChoice(int& row, int& col) {
    while (true) {
        cout << "Enter row (1-3): ";
        // Valida la entrada de la fila
        while (!(cin >> row) || row < 1 || row > 3) {
            cout << "Invalid row. Please enter a number between 1 and 3: ";
            cin.clear(); // Limpia el flag de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el resto de la línea
        }

        cout << "Enter column (1-3): ";
        // Valida la entrada de la columna
        while (!(cin >> col) || col < 1 || col > 3) {
            cout << "Invalid column. Please enter a number between 1 and 3: ";
            cin.clear(); // Limpia el flag de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el resto de la línea
        }

        // Ajusta las coordenadas para que sean índices de array (0-2)
        row--;
        col--;

        // Comprueba si la carta ya ha sido revelada (encontrado un par)
        if (revealed[row][col]) {
            cout << "This card has already been revealed. Choose another one.\n";
            waitForEnter(); // Espera para que el usuario lea el mensaje
            showBoard(); // Vuelve a mostrar el tablero
        } else {
            break; // Las coordenadas son válidas y la carta no está revelada, sale del bucle
        }
    }
}

/**
 *  Función principal de la misión "Búsqueda de Información" (Misión 1 de Kepler-45).
 *
 * Implementa un juego de memoria donde el jugador debe encontrar pares de palabras
 * ocultas en un tablero 3x3.
 */
void play() {
    system("cls"); // Limpia la pantalla
    // Introducción a la misión
    cout << "Noctriz has arrived at Kepler-45. An ancient alien artifact holds vital information,\n";
    cout << "but it's protected by a memory puzzle. You must find the matching pairs to unlock it.\n";
    cout << "Concentration and a good memory will be key!\n\n";
    waitForEnter(); // Espera a que el usuario presione Enter

    initializeGame(); // Inicializa el tablero del juego
    pairsFound = 0;   // Reinicia el contador de pares encontrados

    // Bucle principal del juego. Continúa hasta que se encuentren todos los pares (4 pares).
    while (pairsFound < 4) {
        showBoard(); // Muestra el estado actual del tablero

        cout << "Select the first card:\n";
        int row1, col1;
        getCardChoice(row1, col1); // Obtiene la primera carta elegida por el usuario

        // Revela temporalmente la primera carta para que el usuario la vea
        revealed[row1][col1] = true;
        showBoard(); // Vuelve a mostrar el tablero con la primera carta revelada

        cout << "Select the second card:\n";
        int row2, col2;
        getCardChoice(row2, col2); // Obtiene la segunda carta elegida por el usuario

        // Si el usuario elige la misma carta dos veces, se le pide que elija de nuevo.
        if (row1 == row2 && col1 == col2) {
            cout << "You selected the same card twice. Please choose a different card.\n";
            // La primera carta vuelve a ocultarse ya que no se ha elegido una segunda válida.
            revealed[row1][col1] = false;
            waitForEnter();
            continue; // Reinicia el bucle para que el usuario elija de nuevo
        }

        // Revela temporalmente la segunda carta
        revealed[row2][col2] = true;
        showBoard(); // Muestra el tablero con ambas cartas reveladas

        // Imprime las palabras de las cartas elegidas para que el usuario las compare.
        cout << "\nCard 1: " << boardWords[row1][col1];
        cout << " | Card 2: " << boardWords[row2][col2] << "\n";

        // Compara si las palabras de las dos cartas son iguales
        if (boardWords[row1][col1] == boardWords[row2][col2]) {
            // Si son iguales, comprueba si es la carta "Bonus"
            if (boardWords[row1][col1] == "Bonus") {
                cout << "\nBONUS FOUND! +10 points!\n"; // Mensaje especial para el bonus
                globalScore += 10; // Suma 10 puntos por el bonus
            } else {
                cout << "\nPAIR FOUND! Excellent work, Noctriz!\n"; // Mensaje de par encontrado
                globalScore += 100; // Suma 100 puntos por cada par
                pairsFound++;       // Incrementa el contador de pares encontrados
            }
        } else {
            cout << "\nNot a match. Keep trying!\n"; // Mensaje de no coincidencia
            waitForEnter(); // Espera a que el usuario lea el mensaje
            // Si no coinciden, las cartas se vuelven a ocultar
            revealed[row1][col1] = false;
            revealed[row2][col2] = false;
            globalScore -= 25; // Resta 25 puntos por un intento fallido
        }

        waitForEnter(); // Pausa después de cada intento para que el usuario vea el resultado
    }

    system("cls"); // Limpia la pantalla al finalizar la misión
    cout << "=======================================\n";
    cout << "   MISSION KEPLER-45: INFORMATION SEARCH\n";
    cout << "=======================================\n\n";

    // Mensaje final de la misión completada
    cout << "Congratulations! You have successfully unlocked the ancient artifact.\n";
    cout << "The vital information about the rogue AI has been retrieved.\n";
    cout << "Noctriz's mission continues! Keep up the great work.\n";
    globalScore += 250; // Bonificación por completar la misión
    waitForEnter(); // Espera la confirmación final del usuario
}

   **_findSupplies_**

   ```cpp
#include <iostream> // Para entrada y salida de datos (cout, cin)
#include <conio.h>    // Para _getch(), que permite leer caracteres sin presionar Enter, y códigos de flecha
#include <cstdlib>    // Para system("cls") para limpiar la pantalla
#include <limits>     // Para numeric_limits, utilizado para limpiar el buffer de entrada

#include "findSupplies.h" // Incluye el archivo de encabezado de esta misión
#include "utils.h"        // Incluye las utilidades compartidas, como globalScore y waitForEnter()

using namespace std; // Usa el espacio de nombres estándar

/* ---------- Laberinto 10 × 10 ---------- */
// 'N' es Noctriz (jugador), '.' es camino, '#' es obstáculo/asteroide, 'S' es suministro
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
int playerRow = 0, playerCol = 0; // Posición inicial de Noctriz (N) en el laberinto
int moves = 50;                   // Número máximo de movimientos permitidos para el jugador
int supplies = 5;                 // Número total de suministros a recolectar

/**
 *  Imprime el laberinto en la consola.
 *
 * Muestra el estado actual del laberinto, incluyendo la posición de Noctriz,
 * obstáculos y suministros.
 */
void printMaze() {
    system("cls"); // Limpia la pantalla
    cout << "=== MISSION KEPLER-45: SUPPLIES RECOVERY ===\n"; // Título de la misión
    cout << "Current Score: " << globalScore << "\n\n"; // Muestra la puntuación actual

    cout << "Moves left: " << moves << " | Supplies collected: " << (5 - supplies) << "/5\n\n"; // Muestra el estado del juego

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << maze[i][j] << " "; // Imprime cada celda del laberinto
        }
        cout << "\n"; // Salto de línea al final de cada fila
    }
    cout << "\nUse arrow keys to move (Up, Down, Left, Right).\n"; // Instrucciones para el usuario
}

/**
 *  Función principal de la misión "Recuperación de Suministros" (Misión 2 de Kepler-45).
 *
 * Implementa un juego de laberinto donde el jugador (Noctriz) debe recolectar
 * suministros evitando obstáculos y dentro de un límite de movimientos.
 */
void findSupplies() {
    system("cls"); // Limpia la pantalla
    // Introducción a la misión
    cout << "Noctriz has retrieved vital information, but the ship's fuel is low.\n";
    cout << "You must navigate through an asteroid field to collect essential supplies.\n";
    cout << "Be careful! Every collision drains your remaining fuel.\n\n";
    waitForEnter(); // Espera a que el usuario presione Enter

    // Reinicia las variables del juego para asegurar un nuevo inicio
    playerRow = 0;
    playerCol = 0;
    moves = 50;
    supplies = 5;

    // Reinicia el laberinto a su estado original (copia del laberinto inicial)
    char initialMaze[10][10] = {
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
    // Copia el laberinto inicial al laberinto de juego
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            maze[i][j] = initialMaze[i][j];
        }
    }


    printMaze(); // Muestra el laberinto inicial

    // Bucle principal del juego. Continúa mientras haya movimientos disponibles
    // y no se hayan recolectado todos los suministros.
    while (moves > 0 && supplies > 0) {
        int key = _getch(); // Lee una tecla sin necesidad de presionar Enter

        int nextR = playerRow; // Posición de la siguiente fila (tentativa)
        int nextC = playerCol; // Posición de la siguiente columna (tentativa)

        // Manejo de la entrada del usuario con códigos de flecha
        if (key == 224) { // Código especial para las teclas de flecha
            key = _getch(); // Lee el segundo código para determinar la flecha específica
            switch (key) {
                case 72: nextR--; break; // Flecha arriba
                case 80: nextR++; break; // Flecha abajo
                case 75: nextC--; break; // Flecha izquierda
                case 77: nextC++; break; // Flecha derecha
            }
        } else if (key == 'q' || key == 'Q') { // El jugador decide rendirse
            cout << "\nNoctriz decided to abort the mission. Too many obstacles ahead...\n";
            globalScore -= 100; // Penalización por rendirse
            waitForEnter();
            return; // Sale de la función
        }

        moves--; // Decrementa los movimientos restantes en cada turno

        // Valida si la próxima posición es válida (dentro de los límites del laberinto)
        if (nextR < 0 || nextR >= 10 || nextC < 0 || nextC >= 10) {
            cout << "\nOut of bounds! Choose a valid path.\n"; // Mensaje si se sale del laberinto
            globalScore -= 10; // Penalización por intento inválido
            waitForEnter();
        } else if (maze[nextR][nextC] == '#') { // Si la próxima posición es un obstáculo ('#')
            cout << "\nCollision! You hit an asteroid. Fuel drained!\n"; // Mensaje de colisión
            globalScore -= 20; // Penalización por colisión
            waitForEnter();
        } else {
            // Si la próxima posición es válida y no es un obstáculo, se mueve Noctriz
            char target = maze[nextR][nextC]; // Carácter en la celda de destino
            if (target == 'S') { // Si se encuentra un suministro
                supplies--;   // Decrementa el contador de suministros restantes
                globalScore += 75; // Suma puntos por recoger un suministro
                cout << "Supply collected! Remaining: " << supplies << "\n"; // Mensaje de suministro recogido
                waitForEnter();
            }

            maze[playerRow][playerCol] = '.'; // La posición anterior de Noctriz se convierte en camino '.'
            playerRow = nextR; // Actualiza la fila de Noctriz a la nueva posición
            playerCol = nextC; // Actualiza la columna de Noctriz a la nueva posición
            maze[playerRow][playerCol] = 'N'; // Coloca a Noctriz en la nueva posición
        }

        printMaze(); // Vuelve a imprimir el laberinto con la posición actualizada
    }

    system("cls"); // Limpia la pantalla al finalizar la misión
    cout << "=======================================\n";
    cout << "   MISSION KEPLER-45: SUPPLIES RECOVERY\n";
    cout << "=======================================\n\n";

    // Determina el resultado de la misión (éxito o fracaso)
    if (supplies == 0) { // Si se recolectaron todos los suministros
        cout << "Mission accomplished! You've obtained enough supplies to repair the ship.\n"; // Misión cumplida
        cout << "Noctriz can continue his journey. Algoritmia awaits you!\n"; // Continuación de la victoria
        globalScore += 200; // Bonificación por éxito
    } else { // Si se agotaron los movimientos o no se recolectaron todos los suministros
        cout << "Out of fuel... Noctriz's ship is stranded.\n"; // Combustible agotado
        cout << "Too many asteroid collisions. Mission failed.\n"; // Misión fallida
        globalScore -= 150; // Penalización por fracaso
    }
    waitForEnter(); // Espera la confirmación final del usuario
}

**_src/spaceRace_**

```cpp
#include <iostream> // Para entrada y salida de datos (cout, cin)
#include <cstdlib>  // Para funciones de utilidad general, como system("cls") y srand
#include <ctime>    // Para la función time(), utilizada en srand para inicializar el generador de números aleatorios
#include <string>   // Para el manejo de cadenas de texto (string)
#include <limits>   // Para numeric_limits, utilizado para limpiar el buffer de entrada

#include "spaceRace.h" // Incluye el archivo de encabezado de esta misión (declaraciones de funciones)
#include "utils.h"     // Incluye las utilidades compartidas, como globalScore y waitForEnter()

using namespace std; // Usa el espacio de nombres estándar para evitar prefijar cout, cin, etc. con std::

const int TRACK_LEN = 30;   // Define la longitud de la pista de carrera

/**
 *  Dibuja una línea de carrera para una nave en la consola.
 *
 * Esta función imprime la pista de carrera, la posición actual de la nave
 * y la línea de meta.
 *
 *  pos La posición actual de la nave en la pista.
 * icon El icono (string) que representa la nave del jugador o la IA.
 */
void drawLine(int pos, string icon) {
    for (int i = 0; i < TRACK_LEN; ++i) {
        if (i == pos)
            cout << icon;      // Imprime el icono de la nave en su posición actual
        else if (i == TRACK_LEN - 1)
            cout << "|";       // Imprime la línea de meta al final de la pista
        else
            cout << " ";       // Imprime un espacio vacío para representar la pista
    }
    cout << "\n"; // Salto de línea al final de cada línea de carrera
}

/**
 *  Función principal de la misión "Restablecimiento de Conexión" (Misión 1 de PSR).
 *
 * Esta función implementa un juego de carrera espacial donde el jugador compite
 * contra una IA para reestablecer la conexión con Algoritmia.
 * El jugador y la IA avanzan aleatoriamente en cada turno.
 */
void spaceRace () {
    system("cls"); // Limpia la pantalla de la consola

    // Muestra la introducción a la misión
    cout << "Noctriz has arrived at PSR, but the connection with Algoritmia has been lost.\n";
    cout << "To reestablish it, you must win a spaceship race against an AI prototype.\n";
    cout << "Speed and luck will decide if you can send the rescue signal!\n\n";
    waitForEnter(); // Espera a que el usuario presione Enter para continuar

    // Inicializa el generador de números aleatorios con la hora actual.
    // Esto asegura que los números generados sean diferentes en cada ejecución.
    srand(static_cast<unsigned>(time(nullptr)));

    int playerPos = 0; // Posición inicial del jugador en la pista
    int cpuPos    = 0; // Posición inicial de la IA en la pista
    string input;      // Variable para almacenar la entrada del usuario

    system("cls"); // Limpia la pantalla para el inicio de la carrera
    cout << "=== MISSION PSR: CONNECTION REESTABLISHMENT ===\n"; // Título de la misión
    cout << "Current Score: " << globalScore << "\n\n"; // Muestra la puntuación actual del jugador
    cout << "Spaceship Race!\n" // Título de la carrera
         << "Press Enter to advance, type \"Q\" to quit the race.\n\n"; // Instrucciones para el jugador
    waitForEnter(); // Pausa antes de empezar la carrera para que el jugador lea las instrucciones

    // Bucle principal de la carrera. Continúa mientras ni el jugador ni la IA
    // hayan alcanzado la línea de meta (TRACK_LEN - 1).
    while (playerPos < TRACK_LEN - 1 && cpuPos < TRACK_LEN - 1) {
        system("cls"); // Limpia la pantalla para "animar" el movimiento de las naves
        cout << "=== MISSION PSR: CONNECTION REESTABLISHMENT ===\n"; // Título de la misión
        cout << "Current Score: " << globalScore << "\n\n"; // Muestra la puntuación actual

        // Dibuja las pistas con las posiciones actuales de las naves
        cout << "Your Ship: ";
        drawLine(playerPos, "A>"); // Dibuja la nave del jugador
        cout << "AI Ship:   ";
        drawLine(cpuPos, "B>");     // Dibuja la nave de la IA
        cout << "\n";

        cout << "Press Enter to advance, type \"Q\" to quit the race: ";
        getline(cin, input); // Lee la entrada del usuario (Enter o 'Q')

        if (input == "Q" || input == "q") { // Si el jugador decide rendirse
            cout << "\nNoctriz decided to abort the race. The signal could not be sent.\n";
            globalScore -= 100; // Penalización por rendirse
            waitForEnter();
            return; // Sale de la función
        }
        // El jugador avanza 1 o 2 posiciones aleatoriamente
        playerPos += (rand() % 2) + 1;

        // La IA avanza 1 o 2 posiciones aleatoriamente
        cpuPos += (rand() % 2) + 1;
    }

    system("cls"); // Limpia la pantalla al finalizar la carrera
    cout << "=======================================\n";
    cout << "   MISSION PSR: CONNECTION REESTABLISHMENT\n"; // Título de la misión
    cout << "=======================================\n\n";

    // Determina el resultado de la carrera (empate, victoria del jugador o derrota)
    if (playerPos >= TRACK_LEN - 1 && cpuPos >= TRACK_LEN - 1) {
        cout << "It's a tie! The signal is weak but something happened.\n"; // Mensaje de empate
        globalScore += 50; // Puntos por empate
    } else if (playerPos >= TRACK_LEN - 1) {
        cout << "You won the race! The signal has been successfully sent!\n"; // Mensaje de victoria
        cout << "Algoritmia has received your message. Well done, Noctriz!\n"; // Mensaje de victoria
        globalScore += 250; // Bonificación por ganar
    } else {
        cout << "The AI won the race! The connection is still cut.\n"; // Mensaje de derrota
        cout << "Noctriz could not send the signal. We must find another way!\n"; // Mensaje de derrota
        globalScore -= 150; // Penalización por fracaso
    }
    waitForEnter(); // Espera la confirmación final del usuario
}

   **_guessPassword__**

   ```cpp
#include <iostream> // Para entrada y salida de datos (cout, cin)
#include <cstdlib>  // Para funciones de utilidad general, como system("cls") y srand
#include <ctime>    // Para la función time(), utilizada en srand para inicializar el generador de números aleatorios
#include <string>   // Para el manejo de cadenas de texto (string)
#include <cctype>   // Para tolower(), que convierte un carácter a minúscula
#include <limits>   // Para numeric_limits, utilizado para limpiar el buffer de entrada

#include "guessPassword.h" // Incluye el archivo de encabezado de esta misión
#include "utils.h"         // Incluye las utilidades compartidas, como globalScore y waitForEnter()

using namespace std; // Usa el espacio de nombres estándar

// Variables globales del juego del ahorcado (definidas aquí, no en el .h)
string word;          // La palabra secreta que se va a adivinar (la contraseña)
string guessedLetters = ""; // Una cadena que almacena todas las letras que el jugador ha intentado

// Array de palabras predefinidas para la contraseña
string wordsToGuess[] = {
    "ALGORITMIA", "NEBULA", "COSMOS", "EXPLORER", "GRAVITY",
    "INTERSTELLAR", "MISSION", "ORBIT", "PLANET", "STARSHIP"
};
const int NUM_WORDS = 10; // Número de palabras en el array `wordsToGuess`

/**
 *  Dibuja el cuerpo del "ahorcado" en la consola.
 *
 * La representación visual del ahorcado cambia según el número de vidas restantes.
 *
 *  life El número de vidas restantes del jugador.
 */
void body(int life) {
    cout << " ________" << endl;
    cout << " |      |" << endl;
    if (life < 6) cout << " |      O" << endl; else cout << " |" << endl; // Cabeza
    if (life < 4) cout << " |     /|\\ " << endl; else if (life < 5) cout << " |      |" << endl; else cout << " |" << endl; // Cuerpo y brazos
    if (life < 2) cout << " |     / \\ " << endl; else if (life < 3) cout << " |     / " << endl; else cout << " |" << endl; // Piernas
    cout << " |" << endl;
    cout << "_|_ " << endl;
}

/**
 * Muestra el progreso actual de la adivinanza de la palabra.
 *
 * Las letras adivinadas se muestran, y las no adivinadas se representan con guiones bajos.
 */
void showProgress() {
    cout << "\nWord: "; // Etiqueta de la palabra
    for (char c : word) { // Itera sobre cada carácter de la palabra secreta
        // Si la letra ya ha sido adivinada (está en `guessedLetters`), la muestra.
        // `string::npos` significa que no se encontró la letra.
        if (guessedLetters.find(c) != string::npos) {
            cout << c << " "; // Muestra la letra
        } else {
            cout << "_ "; // Si no ha sido adivinada, muestra un guion bajo
        }
    }
    cout << "\n";
}

/**
 *  Función principal de la misión "Descifrando Contraseña" (Misión 2 de PSR).
 *
 * Implementa un juego tipo "ahorcado" donde el jugador debe adivinar una contraseña (palabra)
 * letra por letra. Tiene un número limitado de intentos (vidas).
 */
void guessPassword() {
    system("cls"); // Limpia la pantalla
    // Introducción a la misión
    cout << "Noctriz has finally reached the AI's core, but a final barrier remains:\n";
    cout << "a password-protected terminal. You must decipher the password to neutralize the AI.\n";
    cout << "Think carefully, agent, your lives depend on it!\n\n";
    waitForEnter(); // Espera a que el usuario presione Enter

    // Inicializa el generador de números aleatorios para elegir una palabra al azar.
    srand(static_cast<unsigned>(time(nullptr)));
    // Elige una palabra aleatoria del array `wordsToGuess`
    word = wordsToGuess[rand() % NUM_WORDS];
    guessedLetters = ""; // Reinicia las letras adivinadas para un nuevo juego
    int live = 6;       // Número inicial de vidas para el jugador (6 intentos erróneos)

    // Bucle principal del juego. Continúa mientras al jugador le queden vidas y
    // no haya adivinado la palabra completa.
    while (live > 0) {
        system("cls"); // Limpia la pantalla para cada turno
        cout << "=== MISSION PSR: DECRYPTING THE PASSWORD ===\n"; // Título de la misión
        cout << "Current Score: " << globalScore << "\n"; // Muestra la puntuación actual
        body(live);       // Dibuja el estado actual del ahorcado
        showProgress();   // Muestra el progreso de la palabra adivinada

        cout << "\nGuessed letters: " << guessedLetters << "\n"; // Muestra las letras ya intentadas

        char guess; // Variable para almacenar la letra adivinada por el usuario
        cout << "Enter a letter: ";
        cin >> guess; // Lee la letra
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada

        guess = toupper(guess); // Convierte la letra a mayúscula para comparación (las palabras están en mayúscula)

        // Comprueba si la letra ya ha sido intentada
        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter. Try another one.\n";
            waitForEnter();
            continue; // Salta al siguiente turno sin penalización de vida
        }

        guessedLetters += guess; // Añade la letra intentada a la lista de letras adivinadas

        // Comprueba si la letra adivinada está en la palabra secreta
        if (word.find(guess) == string::npos) {
            cout << "Incorrect guess! You lose a life.\n"; // Mensaje de error
            live--; // Decrementa las vidas
            globalScore -= 50; // Penalización por intento incorrecto
        } else {
            cout << "Correct guess! Good job.\n"; // Mensaje de acierto
            globalScore += 20; // Puntos por acierto
        }

        // Comprobar si ya ganó (todas las letras de la palabra están en `guessedLetters`)
        bool won = true;
        for (char c : word) {
            if (guessedLetters.find(c) == string::npos) { // Si alguna letra de la palabra no ha sido adivinada
                won = false; // El jugador aún no ha ganado
                break;       // Sale del bucle
            }
        }

        if (won) {
            system("cls"); // Limpia la pantalla
            cout << "=== MISSION PSR: DECRYPTING THE PASSWORD ===\n"; // Título
            cout << "Current Score: " << globalScore << "\n"; // Puntuación
            showProgress(); // Muestra la palabra completa
            cout << "\nCONGRATULATIONS! You deciphered the password: " << word << "\n"; // Mensaje de victoria
            cout << "The AI's base is open! Noctriz can enter and confront it.\n"; // Mensaje de victoria
            globalScore += 300; // Bonificación por ganar
            break; // Sale del bucle del juego
        }
        waitForEnter(); // Pausa después de cada intento
    }

    system("cls"); // Limpia la pantalla al finalizar la misión
    cout << "=======================================\n";
    cout << "   MISSION PSR: DECRYPTING THE PASSWORD\n"; // Título
    cout << "=======================================\n\n";

    // Determina el resultado de la misión (victoria o derrota)
    if (live < 1) { // Si se agotaron las vidas
        cout << "You ran out of lives! The password was: " << word << "\n"; // Mensaje de derrota
        cout << "The AI has kept its secret. Mission failed.\n"; // Mensaje de derrota
        globalScore -= 200; // Penalización por derrota
    }
    waitForEnter(); // Espera la confirmación final del usuario
}

## ▶️ Executions instructions

1. Clone this repository:
   ```bash
   git clone https://github.com/FDP-01-2025/project-asteroides-con-wifi.git

2. Open the poject with IDE or an code Editor.

3. Compile the file in the terminal:

   *g++ -o OwlRocket ./main.cpp*

4. Run the game with the following command

   *./OwlRocket.exe*
