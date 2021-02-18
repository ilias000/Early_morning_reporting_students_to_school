#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(const string name, const int floorNumber, const int classroomNumber) : name(name), floorNumber(floorNumber), classroomNumber(classroomNumber), inside(false) // constructor
{
    cout << "A New Teacher has been created!" << endl;
    cout << "Name = " << this->name << endl;
    cout << "Floor number = " << floorNumber << endl;
    cout << "Classroom number = " << classroomNumber << endl << endl;
}


Teacher::~Teacher() // destructor
{
    cout << "A Teacher to be destroyed!" << endl;
    cout << "Name = " << this->name << endl;
    cout << "Floor number = " << floorNumber << endl;
    cout << "Classroom number = " << classroomNumber << endl << endl;
}


//  Mutators
void Teacher::setInside() // changes the value of inside
{
    inside = true;
}


void Teacher::print() // prints the teacher
{
    cout << "The teacher is :" << getName() << endl;
}