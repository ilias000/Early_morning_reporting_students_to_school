#include "Staircase.h"
#include "Student.h"
#include <iostream>
using namespace std;

Staircase::Staircase(const int CstrairMax): CstairMax(CstrairMax), numberOfStudents(0) // constructor
{
    cout << "A New Stairecase has been created!" << endl << endl;
    student = new Student*[CstrairMax];
    for(int i = 0 ; i < CstrairMax ; i++)
    {
        student[i] = NULL;
    }
}


Staircase::~Staircase() // destructor
{
    cout << endl <<"A Stairecase to be destroyed!" << endl << endl;
    for(int i = 0 ; i < CstairMax ; i++)
    {
        delete student[i];
    }
    delete[] student;
}


void Staircase::enter(Student * student) // enters a student to the staircase
{
    cout << student->getName() << " enters stairs!" << endl;
    for(int i = 0 ; i < CstairMax ; i++) // make the first free pointer at the array of the staircase for the students point to the student that just entered the staircase
    {
        if(this->student[i] == NULL)
        {
            this->student[i] = student;
            numberOfStudents++;
            break; 
        }
    }
    student->setIs("κλιμακοστάσιο");
}


void Staircase::exit(Student * student) // exits a student from the staircase
{
    cout << student->getName() << " exits stairs!" << endl;
    // finds the pointer inside the array with the students that have entered the staircase 
    // that points to the same memory address as the student pointer that points to the 
    // student we want to exit the staircase and make that pointer point to NULL
    for(int i = 0 ; i < CstairMax ; i++)
    {
        if(this->student[i] == student)
        {
            this->student[i] = NULL;
            numberOfStudents--;
            break;
        }
    }
}


void Staircase::print() // prints the staircase
{
    cout << "People in stairs are: " << endl;
    for(int i = 0 ; i < getCstairMax() ; i++) // printing all the students in the staircase
    {
        if(student[i] != NULL)
        {
            cout << '\t' << '\t';
            student[i]->print();
        }
    }
}