#include <iostream>
#include <string>
#include <cstdlib> // Para system("cls")

// Incluye los archivos de encabezado de las misiones y utilidades
#include "src/utils.h"
#include "src/searchInfo.h"    // Incluido aquí para que main.cpp "conozca" las funciones de las misiones
#include "src/findSupplies.h"
#include "src/spaceRace.h"
#include "src/guessPassword.h"

int main() {
    displayGameIntroduction(); // Muestra la introducción del juego

    int planetChoice;
    bool loadOptionChosen = false; // Nueva variable para saber si se eligió cargar partida
    displayPlanetSelectionMenu(planetChoice, loadOptionChosen); // Muestra el menú y obtiene la elección del planeta

    // Si no se cargó una partida, mostrar el mensaje de inicio de misión
    if (!loadOptionChosen) {
        displayMissionStartMessage(planetChoice); // Muestra el mensaje de inicio de misión
    }
    
    handlePlanetMissions(planetChoice); // Llama a la función que maneja las misiones del planeta

    displayGameSummary(); // Muestra el resumen final del juego

    return 0;
}
