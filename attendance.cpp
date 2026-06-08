#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#include "student.cpp"
using namespace std;

struct AttendanceRecord {
    string date;
    string subject;
    string status;
};

class Attendance : public Student {
private:
    string subject;
    string date;
    string attendance_status;
    vector<AttendanceRecord> records;
public:
    Attendance() : subject(""), date(""), attendance_status("") {}

    void getsubject(){
        cout<<"Enter subject: ";
        cin.ignore();
        getline(cin, subject);
    }
    string getsubjects(){
        return subject;
    }
    void getdate(){
        cout<<"Enter date: ";
        getline(cin, date);
    }
    string get_date(){
        return date;
    }
    void getattendance_status(){
        cout<<"Enter attendance status (p for present, a for absent): ";
        cin>>attendance_status;
        cin.ignore();
    }
    string getattendancestatus(){
        return attendance_status;
    }
    void display(){
        Student::display();
        cout<<"Subject: "<<subject<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Attendance Status: "<<attendance_status<<endl;
    }
    void daily_attendance_update(){
        getsubject();
        getdate();
        getattendance_status();
        if(attendance_status != "p" && attendance_status != "a"){
            cout<<"Invalid status. Record not saved."<<endl;
            return;
        }
        AttendanceRecord r;
        r.date = date;
        r.subject = subject;
        r.status = attendance_status;
        records.push_back(r);
        if(attendance_status == "p")
            cout<<"Student marked Present."<<endl;
        else
            cout<<"Student marked Absent."<<endl;
    }
    void student_subject_attendance(){
    string searchID, searchSubject;
    cout << "Enter Student ID: ";
    cin.ignore();
    getline(cin, searchID);
    cout << "Enter Subject name: ";
    getline(cin, searchSubject);

    ifstream attendancefile("attendance.txt");
    if(!attendancefile.is_open()){
        cout << "Unable to open file." << endl;
        return;
    }

    string line;
    int total = 0, attended = 0;

    while(getline(attendancefile, line)){
        if(line.empty()) continue;
        
        if(line.find(searchID) != string::npos && 
           line.find(searchSubject) != string::npos){
            int last = line.size() - 1;
            while(last >= 0 && line[last] == ' ') last--;
            char statusChar = line[last];
            total++;
            if(statusChar == 'p')
                attended++;
        }
    }
    attendancefile.close();

    if(total == 0){
        cout << "No records found for ID: " << searchID 
             << " in subject: " << searchSubject << endl;
        return;
    }

    float percentage = (float)attended / total * 100;
    cout << "\n====== Attendance Summary ======" << endl;
    cout << "Student ID:       " << searchID << endl;
    cout << "Subject:          " << searchSubject << endl;
    cout << "Total Classes:    " << total << endl;
    cout << "Classes Attended: " << attended << endl;
    cout << "Classes Missed:   " << (total - attended) << endl;
    cout << fixed << setprecision(2);
    cout << "Attendance %:     " << percentage << "%" << endl;
}
    void student_subject_lowattendance_alert(){
    string searchID, searchSubject;
    cout << "Enter Student ID: ";
    cin.ignore();
    getline(cin, searchID);
    cout << "Enter Subject name: ";
    getline(cin, searchSubject);

    ifstream attendancefile("attendance.txt");
    if(!attendancefile.is_open()){
        cout << "Unable to open file." << endl;
        return;
    }

    string line;
    int total = 0, attended = 0;

    while(getline(attendancefile, line)){
        if(line.empty()) continue;
        if(line.find(searchID) != string::npos && 
           line.find(searchSubject) != string::npos){
            int last = line.size() - 1;
            while(last >= 0 && line[last] == ' ') last--;
            char statusChar = line[last];
            total++;
            if(statusChar == 'p')
                attended++;
        }
    }
    attendancefile.close();

    if(total == 0){
        cout << "No records found for ID: " << searchID 
             << " in subject: " << searchSubject << endl;
        return;
    }

    float percentage = (float)attended / total * 100;
    cout << fixed << setprecision(2);
    cout << "\n====== Low Attendance Alert ======" << endl;
    cout << "Student ID: " << searchID << endl;
    cout << "Subject:    " << searchSubject << endl;
    cout << "Attendance: " << percentage << "%" << endl;
    
    if(percentage < 75)
        cout << "WARNING: Below 75%! Attend Classes Regularly." << endl;
    else
        cout << "Attendance is Satisfactory." << endl;
}
};