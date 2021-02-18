#ifndef STAIRCASE_H
#define STAIRCASE_H
#include "Student.h"
#include <iostream>
using namespace std;

class Staircase
{
   int CstairMax, numberOfStudents;
   Student **student;
public:
    Staircase(const int); // constructor
    ~Staircase(); // destructor

    // Accessors
    int getNumberOfStudents() const // returns the value of numberOfStudents
    {return numberOfStudents;}
    int getCstairMax() const // returns the value of the CstairMax
    {return CstairMax;}
    Student ** getStudents() const // returns the array with the studensts
    {return student;}


    void enter(Student *); // enters a student to the staircase
    void exit(Student *); // exits a student from the staircase
    void print(); // prints the staircase
};
#endif