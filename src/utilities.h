#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <cstdlib>

using namespace std;

// Limpiar pantalla
void clrscr() {
    system("cls"); // Para Windows. Usá "clear" si estás en Linux/macOS.
}

// Esperar que el usuario presione Enter
void waitForEnter() {
    cout << endl << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

// Mostrar intro completa: bienvenida, Noctriz y nave
void showIntro() {
    // Mensaje de bienvenida
    cout << "========================================" << endl;
    cout << "   ¡Welcome Algorithm Commander!        " << endl;
    cout << "   Help Noctriz rescue his planet       " << endl;
    cout << "========================================" << endl;
    cout << endl;

    // Mostrar Noctriz
    cout << "This is Noctriz the owl" << endl;
    cout << "      _" << endl;
    cout << "    (o,o)" << endl;
    cout << "   { ' ' '}" << endl;
    cout << "   -^--^-" << endl;
    cout << endl;

    // Mensaje de la misión
    cout << "You need to help Noctriz to save all the members of his planet." << endl;
    cout << "All the population is known as ALGORITMIOS." << endl;
    cout << "They were captured by AI, a horrible villain!" << endl;
    cout << "And your mission is... Help Noctriz to save them all!" << endl;

    cout << endl;

    // Mostrar nave espacial
    cout << "      ^      " << endl;
    cout << "     / \\    " << endl;
    cout << "    /_  \\  " << endl;
    cout << "    |    |    " << endl;
    cout << "    |    |    " << endl;
    cout << "    |_   |    " << endl;
    cout << "   /|    |\\   " << endl;
    cout << "  /||_   |\\  " << endl;
    cout << "    / | \\    " << endl;
    cout << "   *  |  *   " << endl;
    cout << "  *   |   *  " << endl;
    cout << " *    |    * " << endl;
    cout << "*     |     *" << endl;

    waitForEnter();
    clrscr();
}

#endif // UTILITIES_H