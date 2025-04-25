/* roster.h file*/
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "student.h"

class Roster
{
private:
	int dataEnd = -1;
	const static int numStudents = 5;

public:
	/* Creating an array of pointers*/
	Student* classRosterArray[numStudents];

	/* Parsing each set of data identified in student data
	   Adding each student object to classRosterArray*/

	void parseStudentData(string studentData);

	/* add() will set the instane vars and will update the roster */

	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	/* Removing students from the roster by studentID */

	void remove(string studentID);

	/* Printing a separated list of student data */

	void printAll();

	/* printing students avg number of days in 3 courses */

	void printAverageDaysInCourse(string studentID);

	/* verifying student email addresses */

	void printInvalidEmails();

	/* printing out student information for specific degree program */

	void printByDegreeProgram(DegreeProgram degreeProgram);

	/* Destructor */

	~Roster();
};

