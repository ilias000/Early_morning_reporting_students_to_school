#ifndef FLOOR_H
#define FLOOR_H
#include "Classroom.h"
#include "Corridor.h"
#include <iostream>
using namespace std;

class Floor
{   
    Classroom *classroom[6];
    Corridor corridor;
    int numberOfStudentsThatEnteredTheirclass; // The number of all students that have enterd their classroom in this floor
public:
    Floor(const int, const int); // constructor
    ~Floor(); // destructor

    // Accessors
    int getNumberOfStudentsThatEnteredTheirClassrooms() const // returns the number of students that have entered their classrooms
    {return numberOfStudentsThatEnteredTheirclass;}

    void enter(Student *); // enters a student to the floor
    bool canEnterFloor(); // returns true if its not full
    void place(Teacher *); // place the teacher in the floor that his classroom is
    void print(const int); // printing the floor
};
#endif