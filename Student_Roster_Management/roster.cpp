#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "roster.h"


/* ANSI ESCAPE CODES FOR COLORS, for better readability */
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"


/* Parsing each set of data in studentData
   Adding each student object to classRosterArray*/

void Roster::parseStudentData(string studentData)
{
	/* Parsing studentID */
	int itemEnd = studentData.find(",");
	string studentID = studentData.substr(0, itemEnd);

	/* Parsing firstName */
	int itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string firstName = studentData.substr(itemStart, itemEnd - itemStart);

	/* Parsing lastName */
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string lastName = studentData.substr(itemStart, itemEnd - itemStart);

	/* Parsing email */
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string email = studentData.substr(itemStart, itemEnd - itemStart);

	/* Parsing age */
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int age = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	/* Parsing days in course1 */
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse1 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	/* Parsing days in course2 */
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse2 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	/* Parsing days in course3 */
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse3 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	/* Parsing DegreeProgram */
	itemStart = itemEnd + 1;
	itemEnd = studentData.find('/0', itemStart);
	DegreeProgram degreeProgram = SOFTWARE;
	if (studentData.substr(itemStart, itemEnd - itemStart) == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (studentData.substr(itemStart, itemEnd - itemStart) == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else {
		degreeProgram = SOFTWARE;
	}

	/* Adding data to the roster */

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}
/* Sets the instance variables and updates the roster */
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++dataEnd] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

/* Removes students from the roster by studentID*/
void Roster::remove(string studentID)
{
	int i = 0;
	bool foundStudent = false;
	for (i = 0; i < dataEnd; ++i) {
		{
		}
		if (classRosterArray[i]->get_studentID() == studentID) {
			/* Mark that the student was found and remove the student by moving elements up*/
			foundStudent = true;
			int j = i;
			for (j = i; j < dataEnd; ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			dataEnd--;
			cout << "Student " << studentID << "removed from roster." << endl;
		}
	}

	/* Printing message if the student ID was not found*/
	if (foundStudent == false) {
		cout << "Student ID not found." << endl;
	}
}

/* Prints a separated list of student data */

void Roster::printAll()
{
	// Clean output
	cout << RED << left
		<< setw(5) << "ID"
		<< setw(15) << "First name"
		<< setw(15) << "Last name"
		<< setw(30) << "Email address"
		<< setw(10) << "Age"
		<< setw(20) << "Days in course"
		<< setw(15) << "Degree program"
		<< endl << endl << RESET;

	// Call print function from Student class
	int i = 0;
	for (i = 0; i <= dataEnd; ++i) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{

	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->get_studentID() == studentID) {
			int* days = classRosterArray[i]->get_daysInCourse();
			double avgDays = (days[0] + days[1] + days[2]) / 3.0;

			cout << RED << left << setw(10) << studentID << RESET << GREEN << setw(15) << avgDays << RESET << endl;
			return;
		}
	}
}

/* Verifying student email addresses */

void Roster::printInvalidEmails()
{
	bool invalidEmail = false;
	string emailToCheck = "none";
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		emailToCheck = classRosterArray[i]->get_email();

		if (emailToCheck.find('@') == string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}

		else if (emailToCheck.find('.') == string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}

		else if (emailToCheck.find(' ') != string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}
	}

	/* If there are no valid email addresses */

	if (invalidEmail == false) {
		cout << "none found." << endl;
	}
}

/* Printing student information for the degree program */

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	/* Converting degree program enumeration to string */

	string programString = "SOFTWARE";
	if (degreeProgram == SECURITY) {
		programString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		programString = "NETWORK";
	}
	else {
		programString = "SOFTWARE";
	}

	/* Clean output */

	cout << RED << left
		<< setw(5) << "ID"
		<< setw(15) << "First name"
		<< setw(15) << "Last name"
		<< setw(30) << "Email address"
		<< setw(10) << "Age"
		<< setw(20) << "Days in course"
		<< setw(15) << "Degree program"
		<< endl << endl << RESET;
	/* Finding & printing students in the requested program */

	bool studentInProgram = false;
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->get_degreeProgram() == degreeProgram) {
			studentInProgram = true;
			classRosterArray[i]->print();
		}
	}

	/* printing if there are no students in program*/
	if (studentInProgram == false) {
		cout << "None found." << endl;
	}
}

/* Destructor to release memory that was allocated dynamically in roster */

Roster::~Roster()
{
	int i = 0;
	for (i = 0; i < dataEnd; ++i) {
		delete classRosterArray[i];
	}
	cout << "-----------------------" << endl;
	cout << GREEN << "Roster cleared." << endl << RESET;
	cout << "-----------------------" << endl;
}