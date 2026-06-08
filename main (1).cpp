#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include "person.cpp"
#include "student.cpp"
#include "teacher.cpp"
#include "attendance.cpp"
#include <windows.h>
using namespace std;

int main(){
    system("start /B python server.py");  
    Sleep(1500);                           
    system("start http://localhost:8000/gui.html"); 

    cout << "Attendance System is running." << endl;
    cout << "Press Enter to exit." << endl;
    cin.get();
    return 0;
}
