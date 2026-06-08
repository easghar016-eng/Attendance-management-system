#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Person{
private:
    string name;
    int id;
    string contactno;
public:
    Person(){}
    
    int getID(){ 
        return id;
    }
    string getName(){ 
        return name; 
    }
    string getContactno(){ 
        return contactno; 
    }
    virtual void getname(){
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin, name);
    }
    virtual void getid(){
        cout<<"Enter id: ";
        cin>>id;
        cin.ignore();
    }
    virtual void getcontactno(){
        cout<<"Enter contact number: ";
        getline(cin, contactno);
    }
    virtual void display()=0;
};