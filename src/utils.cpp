#include <iostream>
#include <limits> // Para numeric_limits
#include <cstdlib> // Para system("cls")
#include <string>  // Para string

#include "utils.h"
#include "searchInfo.h"    // Para play()
#include "findSupplies.h"  // Para findSupplies()
#include "spaceRace.h"     // Para spaceRace()
#include "guessPassword.h" // Para guessPassword()

using namespace std;

// Definición de la variable global
int globalScore = 0;

// Función para esperar que el usuario presione Enter
void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Muestra la introducción del juego
void displayGameIntroduction() {
    system("cls");
    cout << "=======================================\n";
    cout << "   WELCOME TO NOCTRIZ: THE ALGORITMIA AGENT\n";
    cout << "=======================================\n\n";
    cout << "In a galaxy far, far away, the planet Algoritmia is threatened by a rogue AI.\n";
    cout << "You are Noctriz, a highly trained agent tasked with a crucial mission:\n";
    cout << "to neutralize the AI and restore peace to the galaxy.\n";
    cout << "Your journey will take you to two mysterious planets: Kepler-45 and PSR.\n";
    cout << "Each one holds unique challenges and vital information.\n\n";
    waitForEnter();
}

// Muestra el menú de selección de planeta y obtiene la elección del usuario
void displayPlanetSelectionMenu(int& planetChoice) {
    system("cls");
    cout << "=======================================\n";
    cout << "   SELECT YOUR DESTINATION\n";
    cout << "=======================================\n\n";
    cout << "1. Kepler-45: Information Search & Supplies Recovery\n";
    cout << "2. PSR: Connection Reestablishment & Password Decryption\n\n";
    cout << "Enter your choice (1 or 2): ";

    while (!(cin >> planetChoice) || (planetChoice != 1 && planetChoice != 2)) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin.clear(); // Limpiar el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada inválida
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer después de leer el entero
}

// Muestra el mensaje de inicio de misión basado en la elección del planeta
void displayMissionStartMessage(int planetChoice) {
    system("cls");
    if (planetChoice == 1) {
        cout << "=======================================\n";
        cout << "   PREPARING FOR KEPLER-45 MISSIONS\n";
        cout << "=======================================\n\n";
        cout << "Kepler-45, a planet shrouded in mystery, holds the first clues about the AI.\n";
        cout << "Your missions here will focus on gathering intelligence and securing resources.\n";
    } else { // planetChoice == 2
        cout << "=======================================\n";
        cout << "   PREPARING FOR PSR MISSIONS\n";
        cout << "=======================================\n\n";
        cout << "PSR, a distant outpost, requires your immediate attention to restore vital communications.\n";
        cout << "Your missions here will test your speed and decryption skills.\n";
    }
    cout << "\nGood luck, Agent Noctriz!\n";
    waitForEnter();
}

// Muestra un mensaje intermedio de misión completada
void displayMissionCompleteMessage(int planetChoice) {
    system("cls");
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

// Maneja la ejecución de las misiones según el planeta elegido
void handlePlanetMissions(int planetChoice) {
    if (planetChoice == 1) {
        // Misiones de Kepler-45
        play(); // Misión 1: Búsqueda de Información
        displayMissionCompleteMessage(planetChoice); // Mensaje intermedio
        findSupplies(); // Misión 2: Recuperación de Suministros
    } else { // planetChoice == 2
        // Misiones de PSR
        spaceRace(); // Misión 1: Restablecimiento de Conexión
        displayMissionCompleteMessage(planetChoice); // Mensaje intermedio
        guessPassword(); // Misión 2: Descifrando Contraseña
    }
}

// Muestra el resumen final del juego
void displayGameSummary() {
    system("cls");
    cout << "=======================================\n";
    cout << "   GAME SUMMARY\n";
    cout << "=======================================\n\n";
    cout << "Your adventure as Agent Noctriz has concluded.\n";
    cout << "You faced numerous challenges and proved your worth.\n\n";
    cout << "Final Score: " << globalScore << "\n\n";
    cout << "Thank you for playing 'Noctriz: The Algoritmia Agent'!\n";
    waitForEnter();
}
