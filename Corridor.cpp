#include "Corridor.h"
#include "Student.h"
#include <iostream>
using namespace std;

Corridor::Corridor(const int CcorridorMax):CcorridorMax(CcorridorMax), numberOfStudents(0) // constructor
{
    cout << endl << "A New Corridor has been created!" << endl;
    student = new Student*[CcorridorMax];
    for(int i = 0 ; i < CcorridorMax ; i++)
    {
        student[i] = NULL;
    }
}


Corridor::~Corridor() // destructor
{
    cout << "A Corridor to be destroyed!" << endl << endl ;
    for(int i = 0 ; i < CcorridorMax ; i++)
    {
        delete student[i];
    }
    delete[] student;
}


void Corridor::enter(Student * student)  // enters a student to the corridor
{
    cout << student->getName() << " enters corridor!" << endl;
    for(int i = 0 ; i < CcorridorMax ; i++) // make the first free pointer at the array of the corridor for the students point to the student that just entered the corridor
    {
        if(this->student[i] == NULL)
        {
            this->student[i] = student;
            numberOfStudents++;
            break; 
        }
    }
    student->setIs("διάδρομος");
}


void Corridor::exit(Student * student) // exits a student from the corridor
{
    cout << student->getName() << " exits corridor!" << endl;
    // finds the pointer inside the array with the students that have entered the corridor 
    // that points to the same memory address as the student pointer that points to the 
    // student we want to exit the corridor and make that pointer point to NULL
    for(int i = 0 ; i < CcorridorMax ; i++)
    {
        if(this->student[i] == student)
        {
            this->student[i] = NULL;
            numberOfStudents--;
            break;
        }
    }
}


void Corridor::print() // prints corridor
{
    cout << "People in corridor are: " << endl;
    for(int i = 0 ; i < getCcorridorMax() ; i++) // printing all the students in the corridor
    {
        if(student[i] != NULL)
        {
            cout << '\t' << '\t' << '\t';
            student[i]->print();
        }
    }
}