#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define RESET    "\033[0m"
#define BOLD     "\033[1m"
#define RED      "\033[91m"
#define GREEN    "\033[92m"
#define YELLOW   "\033[93m"
#define CYAN     "\033[96m"
#define WHITE    "\033[97m"

inline void enableColor() {
    system("color");
}

inline void printLine(char c = '=', int len = 56) {
    cout << CYAN;
    for (int i = 0; i < len; i++) cout << c;
    cout << RESET << "\n";
}

inline void printHeader(const string& title) {
    cout << "\n";
    printLine('=');
    cout << BOLD << CYAN << "   " << title << RESET << "\n";
    printLine('=');
}

inline void pressEnter() {
    cout << YELLOW << "\n  Press Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
}
