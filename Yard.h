#ifndef YARD_H
#define YARD_H
#include "Student.h"
#include <iostream>
using namespace std;

class Yard
{
    int CyardMax, numberOfStudents;
    Student **student;
public:
    Yard(const int); // constructor
    ~Yard(); // destructor

    // Accessors
    int getCyardMax() const // returns the value of the CyardMax
    {return CyardMax;}
    int getNumberOfStudents() const // returns the value of numberOfStudents
    {return numberOfStudents;}
    Student ** getStudents() const // returns the array with the studensts
    {return student;}

    void enter(Student *); // enters a student to the yard
    void exit(Student *); // exits a student from the yard
    void print(); // prints the yard
};
#endif