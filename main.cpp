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
        // system("cls"); // Limpiar pantalla al inicio - movido a displayGameIntroduction para asegurar limpieza al inicio del juego

        displayGameIntroduction(); // Muestra la introducción del juego

        int planetChoice;
        displayPlanetSelectionMenu(planetChoice); // Muestra el menú y obtiene la elección del planeta

        displayMissionStartMessage(planetChoice); // Muestra el mensaje de inicio de misión

        handlePlanetMissions(planetChoice); // Llama a la función que maneja las misiones del planeta

        displayGameSummary(); // Muestra el resumen final del juego

        return 0;
    }
