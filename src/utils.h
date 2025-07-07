#ifndef UTILS_H
#define UTILS_H

#include <string>

// Variable global para el puntaje del juego
extern int globalScore;

// Funciones de utilidad
void waitForEnter();
void displayGameIntroduction();
void displayPlanetSelectionMenu(int& planetChoice);
void displayMissionStartMessage(int planetChoice);
void displayMissionCompleteMessage(int planetChoice);
void handlePlanetMissions(int planetChoice);
void displayGameSummary();

#endif // UTILS_H
