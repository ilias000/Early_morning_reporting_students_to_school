#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "Student.h"
#include "Teacher.h"
#include <iostream>
using namespace std;

class Classroom
{
    int CclassMax, numberOfStudents;
    Student **student;
    Teacher *teacher;
public:
    Classroom(const int); // constructor
    ~Classroom(); // destructor

    bool canEnterClassroom(); // returns true if some student can enter the classroom
    void enter(Student *); // enters a student to the classroom
    void place(Teacher *); // place the teacher in the classroom 
    void print(const int); // prints the classroom
};
#endif