#ifndef MESSAGES_H
#define MESSAGES_H

#include <iostream>
#include <string>
using namespace std;

void memorama_messages(){
    cout << "============================" << endl;
    cout << "====WELCOME TO MEMORAMA=====" << endl;
    cout << "============================" << endl << endl;
    cout << "In this game you have to find the matching words on each card"<< endl;
    cout << "for each pair you find you will get points, but if you fail" << endl;
    cout << "to find a pair you will be subtracted 2 points" << endl << endl;
    cout << "Good Luck!" << endl;
}

void hangman_messages(){
    cout << "===========================" << endl;
    cout << "=====WELCOME TO HANGED=====" << endl;
    cout << "===========================" << endl << endl;
    cout << "Your mission is to discover the random word in as few tries" << endl;
    cout << "as possible, you lose if you complete the drawing of the hanged man" << endl << endl;
    cout << "Let's GO!";
}


#endif