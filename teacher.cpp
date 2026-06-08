#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include "person.cpp"
using namespace std;
class Teacher:public Person{
private:
    string subject;
public:
    Teacher(){}
    void getsubject(){
        cout<<"Enter subject: ";
        cin>>subject;
    }
    string getsubjects(){
        return subject;
    }
    void show(){
        cout <<"Teacher has been added Successfully!"<<endl;
    }
    void display(){
        cout<<"Name: "<< Person::getName()<<endl;
        cout<<"ID: "<<Person::getID()<<endl;
        cout<<"Contact Number: "<<Person::getContactno()<<endl;
        cout<<"Subject: "<<subject<<endl;
    }
};