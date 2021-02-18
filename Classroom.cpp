#include "Classroom.h"
#include <iostream>
using namespace std;

Classroom::Classroom(const int CclassMax):CclassMax(CclassMax), numberOfStudents(0), teacher(NULL) // constructor
{
    cout << "A New Classroom has been created!" << endl;
    student = new Student*[CclassMax];
    for(int i = 0 ; i < CclassMax ; i++)
    {
        student[i] = NULL;
    }
}


Classroom::~Classroom() // destructor
{
    cout << "A Classroom to be destroyed!" << endl << endl;
    for(int i = 0 ; i < CclassMax ; i++)
    {
        delete student[i];
    }
    delete[] student;
    delete teacher;
}

bool Classroom::canEnterClassroom() // returns true if some student can enter the classroom
{
    if((numberOfStudents < CclassMax) && (teacher == NULL)) // if the classroom is not full and the teacher is not in the classroom the student can enter the classroom
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Classroom::enter(Student * student) // enters a student to the classroom
{
    cout << student->getName() << " enters classroom!" << endl;
    for(int i = 0 ; i < CclassMax ; i++) // make the first free pointer at the array of the corridor for the students point to the student that just entered the corridor
    {
        if(this->student[i] == NULL)
        {
            this->student[i] = student;
            numberOfStudents++;
            break; 
        }
    }
    student->setIs("τάξη");
}

void Classroom::place(Teacher * teacher) // place the teacher in the classroom
{
    this->teacher = teacher;
    teacher->setInside();
}


void Classroom::print(const int classroomNumber) // prints the classroom
{
    cout << '\t' << '\t' << "People in class " << classroomNumber << " are: " << endl;
    if(teacher != NULL) // if the teacher has entered the class
    {
        cout << '\t' << '\t' << '\t';
        teacher->print(); // printing the teacher
    }
    for(int i = 0 ; i < CclassMax ; i++) // printing the students
    {
        if(student[i] != NULL)
        {
            cout << '\t' << '\t' << '\t';
            student[i]->print();
        }
    }
}