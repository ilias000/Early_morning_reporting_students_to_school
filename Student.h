#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

class Student
{
    string name, is;
    int floorNumber, classroomNumber;
public:
    Student(const string, const int, const int); // constructor
    ~Student(); // destructor

    //  Mutators
    void setIs(const string); // changes the value of is (which represents where the student is)

    // Accessors
    string getName() const // returns the name of the student
    {return name;}
    int getFloorNumber() const // returns the value of the floorNumber
    {return floorNumber;}
    int getClassroomNumber() const // returns the value of the classroomNumber
    {return classroomNumber;}

    void print(); // prints the student
};
#endif