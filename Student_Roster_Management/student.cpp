// student.cpp file
#include<iostream>
#include<string>
#include <iomanip> // for pretty output
using namespace std;
#include "student.h"

/*Creating the student class in the student.cpp file*/

/*Default constructor*/

Student::Student()
{
	this->studentID = "none";
	this->firstName = "none";
	this->lastName = "none";
	this->email = "none";
	this->age = 0;
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = SOFTWARE;
}

/* Constructor using all of the input params provided in the table*/

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

/* Creating a getter for each instance variable */

string Student::get_studentID() {
	return this->studentID;
}
string Student::get_firstName() {
	return this->firstName;
}
string Student::get_lastName() {
	return this->lastName;
}
string Student::get_email() {
	return this->email;
}
int Student::get_age() {
	return this->age;
}
int* Student::get_daysInCourse() {
	return this->daysInCourse;
}
DegreeProgram Student::get_degreeProgram() {
	return this->degreeProgram;
}

/* Creating setters for each instance variable */


void Student::set_studentID(string studentID) {
	this->studentID = studentID;
}
void Student::set_firstName(string firstName) {
	this->firstName = firstName;
}
void Student::set_lastName(string lastName) {
	this->lastName = lastName;
}
void Student::set_email(string email) {
	this->email = email;
}
void Student::set_age(int age) {
	this->age = age;
}
void Student::set_daysInCourse(int daysInCourse[]) {
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::set_degreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

/* printing student data*/

void Student::print()
{
	/*degree program enum to string "SECURITY, NETWORK, SOFTWARE"*/


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

	cout << left
		<< setw(5) << studentID
		<< setw(15) << firstName
		<< setw(15) << lastName
		<< setw(30) << email
		<< setw(10) << age
		<< setw(5) << daysInCourse[0]
		<< setw(5) << daysInCourse[1]
		<< setw(10) << daysInCourse[2]
		<< setw(15) << programString
		<< endl;


}

// Destructor

Student::~Student() {

}