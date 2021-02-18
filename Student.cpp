#include "Student.h"
#include <iostream>
using namespace std;

Student::Student( const string name, const int floorNumber, const int classroomNumber) : name(name), is("εκτός σχολικού κτηρίου"), floorNumber(floorNumber), classroomNumber(classroomNumber) // constructor
{
    cout << "A New Student has been created!" << endl;
    cout << "Name = " << this->name << endl;
    cout << "Floor number = " << this->floorNumber << endl;
    cout << "Classroom number = " << this->classroomNumber << endl << endl;
}


Student::~Student() // destructor
{
    cout << "A Student to be destroyed!" << endl;
    cout << "Name = " << this->name << endl;
    cout << "Floor number = " << floorNumber << endl;
    cout << "Classroom number = " << classroomNumber << endl;
    cout << "Is = " << is << endl << endl;
}


//  Mutators
void Student::setIs(const string is) // changes the value of is (which represents where the student is)
{
    this->is = is;
}


void Student::print() // prints the student
{
    cout << getName() << endl;
}