/*
Problem Statement:
Create a Student Management System that simulates a school environment where student information is managed using Object-Oriented Programming principles. 
You need to implement a system that can store and display information about students, including their name, roll number, and marks for three subjects. 
The system should be able to calculate the average marks and determine whether the student has passed or failed.
*/

#include<iostream>
#include<string>

using namespace std;

class Student{
private:
    string name;
    int roll;
    float marks[4];
public:
    Student(string n,int r){
        name=n;
        roll=r;
    }
    void setmarks(float m[]){
        for(int i=0;i<4;i++){
            marks[i]=m[i];
        };
    }
    float calculateAvg(){
        float sum=0;
        for(int i=0;i<4;i++){
            sum+=marks[i];
        }
        return sum/4;
    }
    bool isPassed(){
        if(calculateAvg()>=50){
            return true;
        }
    }
    void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"Roll:"<<roll<<endl;
        cout<<"Marks:";
        for(int i=0;i<4;i++){
            cout<<marks[i]<<" ";
        }
        cout<<endl;
        cout<<"Average:"<<calculateAvg()<<endl;
        cout<<"Status:";
        if(isPassed()){
            cout<<"Passed"<<endl;
        }else{
            cout<<"Failed"<<endl;
        }
    }
};

int main(){
    string name;
    int rollNumber;
    float marks[4];

    // Input details for the student
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> rollNumber;
    cout << "Enter marks for 4 subjects: ";
    for (int i = 0; i < 4; i++) {
        cin >> marks[i];
    }

    // Create student object
    Student student(name, rollNumber);
    student.setmarks(marks);

    // Display student details
    student.display();

    return 0;
}
