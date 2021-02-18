#include "School.h"
#include <cstdlib>     
#include <ctime>
#include <iostream>
using namespace std;

School::School(const int CclassMaxStudents, const int CyardMax, const int CstairMax, const int CcorridorMax) : yard(CyardMax), staircase(CstairMax) // constructor
{
   cout << "A New School has been created!" << endl << endl;
   for(int i = 0 ; i < 3 ; i++)
   {
       this->floor[i] = new Floor(CclassMaxStudents, CcorridorMax);
   }
}


School::~School() // destructor
{
    cout << "A School to be destroyed!" << endl;
    for(int i = 0 ; i < 3 ; i++)
    {
        delete this->floor[i];
    }
}
    

bool School::enter(Student ** student, int & studentsWaitingToEnter, const int totalNumberOfStudents) // it takes all the students, the number of students that are waiting to enter the school and the total number of students
{ 
    bool someStudentsEntered = false; // if we can enter any number of students at any space we make it true

    /*enter yard*/
    cout << endl << "~ENTER STUDENTS TO THE YARD (AS MANY AS IT FITS)~" << endl << endl;
    int countOfstudentThatEnteredNow = 0; // counter of students that entered now

    for(int i = 0 ; i < studentsWaitingToEnter ; i++) // entering as many students as it fit by entering one random student at a time from the reamining students
    {
        if(yard.getNumberOfStudents() < yard.getCyardMax()) // if true a student can go to the yard
        {
            int indexOfRandomStudent; 
            do
            {
                indexOfRandomStudent = rand() % (totalNumberOfStudents); // random number between 0 and totalNumberOfStudents - 1 (because it is for the array)
            } while (student[indexOfRandomStudent] == NULL); // the student has already entered so find an other one
            enter(student[indexOfRandomStudent]); // enter the random student to the yard
            student[indexOfRandomStudent] = NULL; // delete the student from the array of students that are waiting to enter the school
            countOfstudentThatEnteredNow++;
            someStudentsEntered = true;
            cout << endl;
        }
        else // at this point can not more students go to the yard so it make sense to break the for loop to save time
        {
            break; // break so the students on the yard can move on to free space if posible
        }
    }
    studentsWaitingToEnter = studentsWaitingToEnter - countOfstudentThatEnteredNow; // updating the number of the students that are waiting to enter the school 

    /*exit yard and enter staircase*/
    cout << endl << "~ENTER STUDENTS TO THE STAIRCASE (AS MANY AS IT FITS)~" << endl << endl;

    Student ** yardStudent = yard.getStudents(); // taking the array with all the students that are inside the yard
    Student * yardSudentToEnterStaircase = NULL; // will point to the student that is going to enter the staircase 
                                                 // because we want first the student to exit the yard and after enter the staircase but when the student exits 
                                                 // the yard we make the pointer at the array of the yard that pointed at this student NULL

    for(int i = 0 ; i < yard.getCyardMax() ; i++)
    {
        if(yardStudent[i] == NULL)
        {
            continue;
        }
        else
        {
            if(staircase.getNumberOfStudents() < staircase.getCstairMax()) // if true student can go to the staircase
            {
                yardSudentToEnterStaircase = yardStudent[i]; // temporary pointer so we can first exit the student from the yard and then enter the student to the staircase
                yard.exit(yardStudent[i]);
                staircase.enter(yardSudentToEnterStaircase);
                someStudentsEntered = true;
                cout << endl;
            }
            else // at this point a student can not go to the staircase so it make sense to break the for loop to save time
            {
                break; // break so the students on the staircase can move on to free space if posible
            }
        }
    }


    /*exit staircase and enter floor*/
    cout << endl << "~ENTER STUDENTS TO THE FLOORS (AS MANY AS IT FITS)~" << endl << endl;

    Student ** staircaseStudent = staircase.getStudents(); // taking the array with all the students that are inside the staircase
    Student *  staircaseSudentToEnterFloor = NULL; // will point to the student that is going to enter the floor 
                                                   // because we want first the student to exit the staircase and after enter the floor but when the student exits 
                                                   // the staircase we make the pointer at the array of the staircase that pointed at this student NULL   

    for(int i = 0 ; i < staircase.getCstairMax() ; i++)
    {
        if(staircaseStudent[i] == NULL)
        {
            continue;
        }
        else
        {
            int floorNumber = staircaseStudent[i]->getFloorNumber() - 1; // floor number of curent student (its - 1 because the 1 floor for a student is the 0 position for the floor array of the school)
            if(floor[floorNumber]->canEnterFloor() == true) // if true student can go to the floor that his class is 
            {
                staircaseSudentToEnterFloor = staircaseStudent[i]; // temporary pointer so we can first exit the student from the staircase and then enter the student to the floor
                staircase.exit(staircaseStudent[i]);
                floor[floorNumber]->enter(staircaseSudentToEnterFloor);
                someStudentsEntered = true;
                cout << endl;
            }
        }
    }
    return someStudentsEntered;
}


void School::enter(Student * student) // enters student to the yard
{
    cout << student->getName() << " enters school!" << endl;
    yard.enter(student);
}


int School::getNumberOfStudentsInClass() const // returns the number of all students that are in the class from all floors
{
    int studentsInClass = 0; // number of all students that are in the class from all floors
    for(int i = 0 ; i < 3 ; i++) // for every floor take the number of students that have entered their classrooms
    {
        studentsInClass = studentsInClass + floor[i]->getNumberOfStudentsThatEnteredTheirClassrooms();
    }
    return studentsInClass;
}


 void School::place(Teacher * teacher) // place the teacher in the school
 {
    int floorNumber = (teacher->getFloorNumber() - 1); // floor number that the teachers classroom is (its - 1 because the 1 floor for a teacher is the 0 position for the floor array of the school)
    floor[floorNumber]->place(teacher);
 }


 void School::print() // prints the school
 {
     cout << "School life consists of: " << endl;
     cout << endl;
     cout << '\t';
     yard.print(); // printing the yard
     cout << endl;
     cout << '\t';
     staircase.print(); // printing the staircase
     cout << endl;
     cout << '\t';
     for(int i = 0 ; i < 3 ; i++) // printing the floors
     {
         int floorNumber = i + 1; // it's i + 1 because the 1 floor is the 0 position for the floor array of the school
         floor[i]->print(floorNumber);
         cout << endl;
         cout << '\t';
     }
 }