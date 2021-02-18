#ifndef CORRIDOR_H
#define CORRIDOR_H
#include <iostream>
#include "Student.h"
using namespace std;

class Corridor
{
    int CcorridorMax, numberOfStudents;
    Student **student;
public:
    Corridor(const int); // constructor
    ~Corridor(); // destructor

    // Accessors
    int getCcorridorMax() const // returns the value of the CcorridorMax
    {return CcorridorMax;}
    int getNumberOfStudents() const // returns the value of the numberOfStudents
    {return numberOfStudents;}
    Student ** getStudents() const // returns the array with the studensts
    {return student;}

    void enter(Student*); // enters a student to the corridor
    void exit(Student*); // exits a student from the corridor
    void print(); // prints corridor
};
#endif