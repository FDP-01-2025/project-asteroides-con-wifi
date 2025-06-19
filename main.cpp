#include <iostream>
#include <space_race.h>
#include <windows.h> // For Sleep()

int main()
{
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
