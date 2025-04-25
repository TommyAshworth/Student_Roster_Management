/*student.h file*/
#pragma once

#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

/*Creating student class variables studentID, firstName, lastName, emailAddress, age, array of number of days to complete course
degree program*/
class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	const static int numCourses = 3;
	int daysInCourse[numCourses];
	DegreeProgram degreeProgram;

public:
	// Default constructor
	Student();

	// Constructor using all of the input params provided in the table
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);

	// Destructor
	~Student();

	/*Creating getters for each instance variable*/
	string get_studentID();
	string get_firstName();
	string get_lastName();
	string get_email();
	int get_age();
	int* get_daysInCourse();
	DegreeProgram get_degreeProgram();

	/*Creating setters for each instance variable*/

	void set_studentID(string studentID);
	void set_firstName(string firstName);
	void set_lastName(string lastName);
	void set_email(string email);
	void set_age(int age);
	void set_daysInCourse(int daysInCourse[]);
	void set_degreeProgram(DegreeProgram degreeProgram);

	// Printing student data

	void print();
};