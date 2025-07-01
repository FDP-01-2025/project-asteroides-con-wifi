#include <iostream>
#include <windows.h> // For Sleep()
#include <cmath>
#include "src/space_race.h"
#include "src/utilities.h"
#include "src/memorama.h"// Include the Memorama game
#include "src/messages.h"
#include "src/Hngman.h" //ahorcado game//


   

int main(){
<<<<<<< HEAD

    showIntro();
=======
>>>>>>> 3fc6a3c29428b419f75e6cbaadaf1ae13fdcb219
    mostrarMenu();


    
    memorama_messages(); // Show welcome message and instructions
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
