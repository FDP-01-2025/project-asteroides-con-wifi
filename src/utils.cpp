#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cctype>

#include "utils.h"
#include "searchInfo.h"
#include "findSupplies.h"
#include "spaceRace.h"
#include "guessPassword.h"

using namespace std;

// Definición real de la variable global
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

// Muestra el menú de selección de planeta
void displayPlanetSelectionMenu(int& planetChoice, bool& loadOptionChosen) {
    system("cls");
    cout << "=======================================\n";
    cout << "   SELECT YOUR DESTINATION\n";
    cout << "=======================================\n\n";
    cout << "1. Kepler-45: Information Search & Supplies Recovery\n";
    cout << "2. PSR: Connection Reestablishment & Password Decryption\n";
    cout << "3. Load Saved Game\n\n";
    cout << "Enter your choice (1, 2 or 3): ";

    int choice;
    while (!(cin >> choice) || (choice < 1 || choice > 3)) {
        cout << "Invalid option. Please enter 1, 2 or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 3) {
        GameState loadedState = loadGame();
        if (loadedState.planet != 0) {
            globalScore = loadedState.score;
            planetChoice = loadedState.planet;
            loadOptionChosen = true;
            cout << "\nGame loaded successfully! Score: " << globalScore
                 << ", Planet: " << (planetChoice == 1 ? "Kepler-45" : "PSR") << "\n";
            waitForEnter();
        } else {
            cout << "\nCould not load game. Starting a new one...\n";
            loadOptionChosen = false;
            cout << "Enter your choice for a new game (1 or 2): ";
            while (!(cin >> planetChoice) || (planetChoice != 1 && planetChoice != 2)) {
                cout << "Invalid option. Please enter 1 or 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } else {
        planetChoice = choice;
        loadOptionChosen = false;
    }
}

// Muestra el mensaje de inicio de misión
void displayMissionStartMessage(int planetChoice) {
    system("cls");
    if (planetChoice == 1) {
        cout << "=======================================\n";
        cout << "   PREPARING FOR KEPLER-45 MISSIONS\n";
        cout << "=======================================\n\n";
        cout << "Kepler-45, a planet shrouded in mystery, holds the first clues about the AI.\n";
        cout << "Your missions here will focus on gathering intelligence and securing resources.\n";
    } else {
        cout << "=======================================\n";
        cout << "   PREPARING FOR PSR MISSIONS\n";
        cout << "=======================================\n\n";
        cout << "PSR, a distant outpost, requires your immediate attention to restore vital communications.\n";
        cout << "Your missions here will test your speed and decryption skills.\n";
    }
    cout << "\nGood luck, Agent Noctriz!\n";
    waitForEnter();
}

// Mensaje de misión completada + opción de guardar
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

    char saveChoice;
    cout << "\nDo you want to save your progress? (y/n): ";
    cin >> saveChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (tolower(saveChoice) == 'y') {
        GameState currentState;
        currentState.score = globalScore;
        currentState.planet = planetChoice;
        saveGame(currentState);
        cout << "Game saved successfully!\n";
    } else {
        cout << "Game not saved.\n";
    }

    waitForEnter();
}

// Ejecuta ambas misiones, independientemente del orden inicial
void handlePlanetMissions(int planetChoice) {
    int secondPlanet = (planetChoice == 1) ? 2 : 1;

    // --- Primera ronda ---
    displayMissionStartMessage(planetChoice);
    if (planetChoice == 1) {
        play();
        displayMissionCompleteMessage(1);
        findSupplies();
    } else {
        spaceRace();
        displayMissionCompleteMessage(2);
        guessPassword();
    }

    // --- Segunda ronda ---
    displayMissionStartMessage(secondPlanet);
    if (secondPlanet == 1) {
        play();
        displayMissionCompleteMessage(1);
        findSupplies();
    } else {
        spaceRace();
        displayMissionCompleteMessage(2);
        guessPassword();
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

// Guarda la partida en un archivo
void saveGame(const GameState& state) {
    ofstream outFile("savegame.dat");
    if (outFile.is_open()) {
        outFile << state.score << endl;
        outFile << state.planet << endl;
        outFile.close();
    } else {
        cout << "Error: Could not open file to save game.\n";
    }
}

// Carga la partida desde un archivo
GameState loadGame() {
    GameState loadedState = {0, 0};
    ifstream inFile("savegame.dat");
    if (inFile.is_open()) {
        inFile >> loadedState.score;
        inFile >> loadedState.planet;
        inFile.close();
    } else {
        cout << "Warning: No saved game file found.\n";
    }
    return loadedState;
}
