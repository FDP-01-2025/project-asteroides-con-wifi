#include <iostream>
#include <windows.h> // For Sleep()
#include <cmath>
#include <utilities.h>
#include <memorama.h>

   

int main(){
    Memorama juego;
    juego.playGame();
    
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
