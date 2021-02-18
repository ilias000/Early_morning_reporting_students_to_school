#include "School.h"
#include <cstdlib>     
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "                             --- THE PROGRAM STARTED ---                                 " << endl ;

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;
	cout << "                       1. Να δημιουργείται ένα σχολικό κτήριο." << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;

	cout << "                                ~ Creating School ~ " << endl << endl;

	int Cclass = stoi(argv[1]), Cyard = stoi(argv[2]), Cstair = stoi(argv[3]), Ccorr = stoi(argv[4]); 
	cout << "Mέγιστη χωρητικότητα class = " << Cclass << endl;
	cout << "Mέγιστη χωρητικότητα yard = " << Cyard << endl;
	cout << "Mέγιστη χωρητικότητα stair = " << Cstair << endl;
	cout << "Mέγιστη χωρητικότητα corridor = " << Ccorr << endl << endl;
	School school(Cclass, Cyard, Cstair, Ccorr);

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;
	cout << "                       2. Να δημιουργούνται οι μαθητές και οι δάσκαλοί του." << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;

	cout << "                                ~ Creating Students ~ " << endl << endl;
	
	srand((unsigned) time(0));
	int totalNumberOfStudents = 18 * Cclass;
	Student * student[totalNumberOfStudents]; // creating a array of pointers to Student objects 

	for(int i = 1, floorNumber = 1, classroomNumber = 1, studentForThisClass = 0 ; i <= totalNumberOfStudents ; i++)
	{
		// random names
		string name[] = {"ΜΑΡΙΑ", "ΕΛΕΝΗ", "ΓΕΩΡΓΙΟΣ", "ΑΙΚΑΤΕΡΙΝΗ", "ΒΑΣΙΛΙΚΗ", "ΚΛΑΙΡΗ", "ΚΩΝΣΤΑΝΤΙΝΟΣ", "ΙΩΑΝΝΗΣ", "ΝΙΚΟΛΑΟΣ", "ΓΕΩΡΓΙΑ", "ΣΟΦΙΑ", "ΑΝΑΣΤΑΣΙΑ", "ΕΥΑΓΓΕΛΙΑ", "ΙΩΑΝΝΑ", "ΧΡΗΣΤΟΣ", "ΠΑΝΑΓΙΩΤΗΣ", "ΒΑΣΙΛΕΙΟΣ", "ΑΘΑΝΑΣΙΟΣ", "ΜΙΧΑΗΛ", "ΣΠΥΡΙΔΩΝ"}; // array to choose a random name 	
		student[i-1] = new Student(name[rand() % 20], floorNumber, classroomNumber); // creating students with random names and inserting them to the array
		studentForThisClass++;
		if(studentForThisClass == Cclass) // this class is full
		{
			classroomNumber++;
			studentForThisClass = 0;
			if(classroomNumber == 7) // all the classrooms of the floor are full
			{
				floorNumber++;
				classroomNumber = 1;
			}
		}
	}

cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "                                ~ Creating Teachers ~ " << endl << endl;

	Teacher * teacher[18]; // creating a array of pointers to Teacher objects 

	for(int i = 1, floorNumber = 1, classroomNumber = 1 ; i <= 18 ; i++, classroomNumber++)
	{
		// random names
		string name[] = {"ΜΑΡΙΑ", "ΕΛΕΝΗ", "ΓΕΩΡΓΙΟΣ", "ΑΙΚΑΤΕΡΙΝΗ", "ΒΑΣΙΛΙΚΗ", "ΚΛΑΙΡΗ", "ΚΩΝΣΤΑΝΤΙΝΟΣ", "ΙΩΑΝΝΗΣ", "ΝΙΚΟΛΑΟΣ", "ΓΕΩΡΓΙΑ", "ΣΟΦΙΑ", "ΑΝΑΣΤΑΣΙΑ", "ΕΥΑΓΓΕΛΙΑ", "ΙΩΑΝΝΑ", "ΧΡΗΣΤΟΣ", "ΠΑΝΑΓΙΩΤΗΣ", "ΒΑΣΙΛΕΙΟΣ", "ΑΘΑΝΑΣΙΟΣ"}; // array to choose a random name 
		// we want every teacher to have a different classroom
		teacher[i-1] = new Teacher(name[rand() % 18], floorNumber, classroomNumber); // creating teachers with random names and inserting them to the array
		if(classroomNumber == 6)
		{
			floorNumber++;
			classroomNumber = 0; 
		}
	}

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << " 3. Να επαναλαμβάνεται η παρακάτω διαδικασία έως ότου είτε να έχουν μπει όλοι οι μαθητές στις τάξεις τους είτε να μην μπορεί να μπει κανένας άλλος μαθητής" << endl; 
	cout << "       (αʹ) Να μπαίνουν μαθητές στο σχολικό κτήριο με τυχαία σειρά" << endl; 
	cout << "       (βʹ) Να επιλέγεται τυχαία αν θα τοποθετούνται δάσκαλοι στις τάξεις τους";
	cout << " ,στην περίπτωση θετικού αποτελέσματος, η επιλογή των δασκάλων για τοποθέτηση να είναι πάλι τυχαία" << endl;
										
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	int studentsWaitingToEnter = totalNumberOfStudents;
	bool canEnterMoreStudents;
	int remainingTeachers = 18;
	do
	{
		canEnterMoreStudents = school.enter(student, studentsWaitingToEnter, totalNumberOfStudents);
	
		int randomNumberOfTeachers = rand() % (remainingTeachers + 1); // random number between [0 and number of remaining teachers] 
		cout << "Entering " << randomNumberOfTeachers << " teachers" << endl;
		if(randomNumberOfTeachers != 0) // we will enter randomNumberOfTeachers (if randomNumberOfTeachers == 0 we will not enter any teacher)
		{
			for(int i = 0 ; i < randomNumberOfTeachers ; i++) // choosing a random teacher from the remaining ones and enter him for randomNumberOfTeachers times
			{
				int randomIndexOfTeacher;
				do
				{
					randomIndexOfTeacher = rand() % 18; // random number from [0 - 17] because it is for the array
				} while (teacher[randomIndexOfTeacher] == NULL); // the teacher has already entered so find an other one
				school.place(teacher[randomIndexOfTeacher]); // place the random teacher in the school
				teacher[randomIndexOfTeacher] = NULL; // delete the teacher from the array of teachers that are waitng to enter the school
				remainingTeachers--; // updating the number of the teachers that are waiting to enter the school 
			}
		}
	}while ((school.getNumberOfStudentsInClass() < totalNumberOfStudents) && (canEnterMoreStudents == true)); // if not all students have entered their class and more students can enter keep calling the enter 


	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;
	cout << "                       4. Να εκτυπώνεται το σχολικό κτήριο." << endl;
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl ;

	school.print();

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "                                ~ Deleting Students ~ " << endl << endl;
	// delete students
	for(int i = 0 ; i < 18 * Cclass ; i++)
	{
		delete student[i];
	}

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "                                ~ Deleting Teachers ~ " << endl << endl;
	// delete teachers
	for(int i = 0 ; i < 18 ; i++)
	{
		delete teacher[i];
	}
	
	cout << "                             --- THE PROGRAM ENDED ---                                 " << endl << endl ;
	return 0;
}