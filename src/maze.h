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

// generates a maze with a guaranteed path
void generateMaze(int maze[lines][columns], float density) {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            maze[i][j] = 1;

    int x = 0, y = 0;
    maze[x][y] = 0;
    srand(time(0));
    while (x < lines - 1 || y < columns - 1) {
        int dir = rand() % 2;
        if (dir == 0 && x < lines - 1) x++;
        else if (y < columns - 1) y++;
        maze[x][y] = 0;
    }

}