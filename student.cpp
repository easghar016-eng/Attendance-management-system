#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include "person.cpp"
using namespace std;
class Student:public Person{
private:
    string course;
    int year;
public:
    Student(){}

    void getcourse(){
        cout<<"Enter course: ";
        cin>>course;
    }
    string getcourse1(){
        return course;
    }
    void getyear(){
        cout<<"Enter year: ";
        cin>>year;
    }
    int getyear1(){
        return year;
    }
    void show(){
        cout <<"Student has been added Successfully!"<<endl;
    }
    void display(){
        cout<<"Name: "<< Person::getName()<<endl;
        cout<<"ID: "<<Person::getID()<<endl;
        cout<<"Contact Number: "<<Person::getContactno()<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Year: "<<year<<endl;
    }
    void display(int id){
        cout<<"Enter id: ";
        cin>>id;
        if(id == getID()){
            display();
        }
        else{
            cout<<"Student with id "<<id<<" not found."<<endl;
        }
    }
    void display(string name) {
        cout<<"Enter name: ";
        cin>>name;
        if(name == name){
            display();
        }
        else{
            cout<<"Student with name "<<name<<" not found."<<endl;
        }
    }
};