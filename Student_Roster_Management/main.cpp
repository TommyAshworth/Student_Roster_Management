#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include "roster.h"
#include "student.h"

// ANSI Escape Codes for Colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

int main() {
    const int numStudents = 5;

    // ** Program Header **
    cout << BLUE << "C867 - Scripting and Programming - Applications\n";
    cout << "C++\n";
    cout << "Student ID: 012389926\n";
    cout << "Name: Tommy Ashworth\n\n" << RESET;

    // ** Student Data Array **
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tommy,Ashworth,tashwo11@wgu.edu,29,30,30,30,SOFTWARE"
    };

    // ** Create Roster Instance **
    Roster classRoster;

    // ** Add Students to Roster **
    for (int i = 0; i < numStudents; ++i) {
        classRoster.parseStudentData(studentData[i]);
    }

    // ** Print Complete Class Roster **
    cout << BLUE << "-----------------------------------------\n";
    cout << "Class Roster:\n";
    cout << "-----------------------------------------\n" << RESET;
    classRoster.printAll();
    cout << endl;

    // ** Print Invalid Email Addresses **
    cout << RED << "-----------------------------------------\n";
    cout << "Invalid Email Addresses:\n";
    cout << "-----------------------------------------\n" << RESET;
    classRoster.printInvalidEmails();
    cout << endl;

    // ** Print Average Days in Course **
    cout << GREEN << "-----------------------------------------\n";
    cout << "Average Days in Course:\n";
    cout << "-----------------------------------------\n" << RESET;

    // Formatting table headers
    cout << BLUE << left << setw(10) << "ID" << setw(10) << "Avg Days" << RESET << endl;
    cout << "-----------------------------------------\n";

    for (int j = 0; j < numStudents; ++j) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[j]->get_studentID());
    }
    cout << endl;

    // ** Print Students in Software Program **
    cout << BLUE << "-----------------------------------------\n";
    cout << "Students in the Software Program:\n";
    cout << "-----------------------------------------\n" << RESET;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    // ** Remove Student (ID: A3) **
    cout << RED << "-----------------------------------------\n";
    cout << "Removing Student A3:\n";
    cout << "-----------------------------------------\n" << RESET;
    classRoster.remove("A3");
    cout << endl;

    // ** Print Updated Class Roster **
    cout << BLUE << "-----------------------------------------\n";
    cout << "Updated Class Roster:\n";
    cout << "-----------------------------------------\n" << RESET;
    classRoster.printAll();
    cout << endl;

    // ** Retry Removing Student A3 **
    cout << RED << "-----------------------------------------\n";
    cout << "Attempting to Remove Student A3 Again:\n";
    cout << "-----------------------------------------\n" << RESET;
    classRoster.remove("A3");
    cout << endl;

    // ** Destructor Execution **
    cout << GREEN << "-----------------------------------------\n";
    cout << "Running Destructor...\n";
    cout << "-----------------------------------------\n" << RESET;
}
