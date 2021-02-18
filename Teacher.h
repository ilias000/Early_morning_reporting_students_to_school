#ifndef TEACHER_H
#define TEACHER_H
#include <string>
#include <iostream>
using namespace std;

class Teacher
{
    string name;
    int floorNumber, classroomNumber;
    bool inside; // if inside == TRUE is inside the classroom
public:
    Teacher(const string, const int, const int); // constructor
    ~Teacher(); // destructor

    //  Mutators
    void setInside(); // changes the value of inside

    // Accessors
    int getFloorNumber() const // returns the value of the floorNumber
    {return floorNumber;}
    int getClassroomNumber() const // returns the value of the classroomNumber
    {return classroomNumber;}
    string getName() const // returns the name of the teacher
    {return name;}

    void print(); // prints the teacher
};
#endif