#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <cstdlib>

using namespace std;

// This function can clear the screen
inline void clrscr() {
    system("cls"); 
}

// This function print a menu
inline void welcome() {
    cout << "========================================" << endl;
    cout << "   ¡Welcome Algorithm Commander!        " << endl;
    cout << "   Help Noctriz rescue his planet       " << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Press any key to continue..." << endl;
    clrscr();
}

// Esta función imprime el menú
inline void menu() {

    cout << endl;
    cout << "      ^     " << endl;
    cout << "     / \\     " << endl;
    cout << "    /___\\    " << endl;
    cout << "    |   |    " << endl;
    cout << "    |   |    " << endl;
    cout << "    |___|    " << endl;
    cout << "   /|   |\\   " << endl;
    cout << "  /_|___|_\\  " << endl;
    cout << "    / | \\    " << endl;
    cout << "   *  |  *   " << endl;
    cout << "  *   |   *  " << endl;
    cout << " *    |    * " << endl;
    cout << "*     |     *" << endl;
}

#endif // UTILITIES_H
