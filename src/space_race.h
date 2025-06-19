#ifndef SRACE_H
#define SRACE_H

/* This library contains the functions to execute the space race game */
#include <iostream>   // Standard input/output stream
#include <cstdlib>    // For system() function
#include <conio.h>    // For _kbhit() and _getch()

using namespace std;

// Constants to define the field size
const int wide = 20;
const int height = 10;

// 2D array representing the game field
char field[height][wide];

// Ship position variables (X = horizontal, Y = vertical)
int shipX = wide / 2;       // Horizontal position (center)
int shipY = height - 1;     // Vertical position (bottom row)

// Display welcome message to the player
void srace_message()
{
    cout << "=====================================" << endl;
    cout << "==========Welcome commander==========" << endl;
    cout << "=====================================" << endl << endl;
    cout << "In this mission you need help Noctriz to win the space race" << endl;
    cout << "The algoritmia people trust in you..." << endl << endl;
    cout << "Press any key to continue..." << endl;
    system("pause");  // Wait for key press
}

// Clear the field and place the ship at its current position
void clearField()
{
    // Fill the entire field with empty spaces
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < wide; j++)
        {
            field[i][j] = ' ';
        }
    }
    // Place the ship character '>' at (shipY, shipX)
    // Note: field is accessed as field[row][column] -> field[y][x]
    field[shipY][shipX] = '>';
}

// Print the current state of the field to the console
void showField()
{
    system("cls"); // Clear the console screen (Windows)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < wide; j++)
        {
            cout << field[i][j];
        }
        cout << endl;
    }
}

// Handle ship movement based on keyboard input (A = left, D = right)
void shipMovement()
{
    if (_kbhit())  // Check if a key was pressed
    {
        char key = _getch();  // Get the pressed key without waiting for Enter

        if (key == 'a' || key == 'A')
        {
            if (shipX > 0)
                shipX--;  // Move ship left if not at the left edge
        }
        else if (key == 'd' || key == 'D')
        {
            if (shipX < wide - 1)
                shipX++;  // Move ship right if not at the right edge
        }
        // You can add more controls here if needed
    }
}

#endif // SRACE_H
