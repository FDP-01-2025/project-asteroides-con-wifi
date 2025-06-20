#include <iostream>
#include <windows.h> // For Sleep()
#include <cmath>
#include "src/space_race.h"
#include "src/utilities.h"
#include "src/memorama.h"// Include the Memorama game

   

int main(){
    Memorama juego; // Initialize the Memorama game
    juego.playGame();// Start the game
    
     srace_message();  // Show welcome message

    while (true)
    {
        shipMovement();  // Check for and handle ship movement input
        clearField();    // Clear and update the field with ship position
        showField();     // Display the updated field

        Sleep(100);      // Delay to control game speed (100 ms)
    }
    return 0;
}
