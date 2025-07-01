#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
char getch() {
    char buf = 0; 
    struct termios old = {};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c
    _lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return buf;
}
#endif

using namespace std;

//variable declaration
const int lines = 10;
const int columns = 20;
const char WALL = '|';
const char PATH = ' ';
const char PLAYER = '@';
const char ENTRY = 'E';
const char EXIT = 'S';

// clear screen function
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


}