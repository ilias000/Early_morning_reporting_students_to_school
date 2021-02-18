#ifndef SCHOOL_H
#define SCHOOL_H
#include "Floor.h"
#include "Yard.h"
#include "Staircase.h"
#include <iostream>
using namespace std;

class School
{
    Floor *floor[3];
    Yard yard;
    Staircase staircase;
public:
    School(const int, const int, const int, const int); // constructor
    ~School(); // destructor

    bool enter(Student **, int &, const int); // enters students to the school
    void enter(Student *); // enters student to the yard
    int getNumberOfStudentsInClass() const; // returns the number of all students that are in the class from all floors
    void place(Teacher *); // place the teacher in the school
    void print(); // prints the school
};
#endif