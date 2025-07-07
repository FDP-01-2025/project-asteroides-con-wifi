#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream> // Necesario para el manejo de archivos

// Variable global para el puntaje del juego
extern int globalScore;

// Estructura para guardar el estado del juego
struct GameState {
    int score;
    int planet; // 1 para Kepler-45, 2 para PSR
};

// Funciones de utilidad
void waitForEnter();
void displayGameIntroduction();
void displayPlanetSelectionMenu(int& planetChoice, bool& loadOptionChosen); // Se añade un parámetro para saber si se eligió cargar
void displayMissionStartMessage(int planetChoice);
void displayMissionCompleteMessage(int planetChoice);
void handlePlanetMissions(int planetChoice);
void displayGameSummary();

// Nuevas funciones para guardar y cargar partida
void saveGame(const GameState& state);
GameState loadGame();

#endif // UTILS_H
