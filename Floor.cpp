#include "Floor.h"
#include <iostream>
using namespace std;

Floor::Floor(const int CclassMaxStudents, const int CcorridorMax) : corridor(CcorridorMax), numberOfStudentsThatEnteredTheirclass(0) // constructor
{
    cout << "A New Floor has been created!" << endl;
    for(int i = 0 ; i < 6 ; i++)
    {
        this->classroom[i] = new Classroom(CclassMaxStudents);
    }
}


Floor::~Floor() // destructor
{
    cout << endl << "A Floor to be destroyed!" << endl << endl;
    for(int i = 0 ; i < 6 ; i++)
    {
        delete this->classroom[i];
    }
}


void Floor::enter(Student * student) // enters a student to the floor
{
    cout << student->getName() << " enters floor!" << endl;
    corridor.enter(student); // the student can enter the corridor because schools enter checked that 

    /*exit corridor enter classroom*/
    Student *  corridorSudentToEnterClassroom= NULL; // will point to the student that is going to enter the classroom 
                                                     // because we want first the student to exit the corridor and after enter the classroom but when the student exits 
                                                     // the corridor we make the pointer at the array of the corridor that pointed at this student NULL

    int classroomNumber = student->getClassroomNumber() - 1; // classroom number of student (its - 1 because the 1 classroom for a student is the 0 position for the classroom array of the floor)
    if(classroom[classroomNumber]->canEnterClassroom() == true) // if true student can go to his class  
    {
        corridorSudentToEnterClassroom = student; // temporary pointer so we can first exit the student from the corridor and then enter the student to the classroom
        corridor.exit(student);
        classroom[classroomNumber]->enter(corridorSudentToEnterClassroom);
        numberOfStudentsThatEnteredTheirclass++;
        cout << endl;
    }
}


bool Floor::canEnterFloor() // returns true if its not full
{
    if(corridor.getNumberOfStudents() < corridor.getCcorridorMax()) // if corridor is not full return true
    {
        return true;
    }
    else 
    {
        return false;
    }
}


void Floor::place(Teacher * teacher) // place the teacher in the floor that his classroom is
{
    int classroomNumber = (teacher->getClassroomNumber() - 1); // number of the teachers classroom (its - 1 because the 1 classroom for a teacher is the 0 position for the classroom array of the floor)
    classroom[classroomNumber]->place(teacher);
}


void Floor::print(const int floorNumber) // printing the floor
{
    cout << "Floor number " << floorNumber << " contains: " << endl;
    cout << endl;
    cout << '\t' << '\t';
    corridor.print(); // printing the corridor
    cout << endl;
    for(int i = 0 ; i < 6 ; i++) // printing the classrooms
    {
        int classroomNumber = i + 1; // it's i + 1 because the 1 classroom is the 0 position for the classroom array of the floor
        classroom[i]->print(classroomNumber);
        cout << endl;
    }
}