 #include "Yard.h"
 #include "Student.h"
 #include <iostream>
 using namespace std;

Yard::Yard(const int CyardMax): CyardMax(CyardMax), numberOfStudents(0) // constructor
{
    cout << "A New Yard has been created!" << endl << endl;
    student = new Student*[CyardMax];
    for(int i = 0 ; i < CyardMax ; i++)
    {
        student[i] = NULL;
    }
}


Yard::~Yard() // destructor
{
    cout << endl << "A Yard to be destroyed!" << endl << endl;
    for(int i = 0 ; i < CyardMax ; i++)
    {
        delete student[i];
    }
    delete[] student;
}


void Yard::enter(Student * student) // enters a student to the yard
{
    cout << student->getName() << " enters schoolyard!" << endl;
    for(int i = 0 ; i < CyardMax ; i++) // make the first free pointer at the array of the yard for the students point to the student that just entered the yard
    {
        if(this->student[i] == NULL)
        {
            this->student[i] = student;
            numberOfStudents++;
            break; 
        }
    }
    student->setIs("προαύλιο");
}


void Yard::exit(Student * student) // exits a student from the yard
{
    cout << student->getName() << " exits schoolyard!" << endl;
    // finds the pointer inside the array with the students that have entered the yard 
    // that points to the same memory address as the student pointer that points to the 
    // student we want to exit the yard and make that pointer point to NULL
    for(int i = 0 ; i < CyardMax ; i++) 
    {
        if(this->student[i] == student)
        {
            this->student[i] = NULL;
            numberOfStudents--;
            break;
        }
    }
}


void Yard::print() // prints the yard
{
    cout << "People in schoolyard are: " << endl;
    for(int i = 0 ; i < getCyardMax() ; i++) // printing all the students in the yard
    {
        if(student[i] != NULL)
        {
            cout << '\t' << '\t';
            student[i]->print();
        }
    }
}