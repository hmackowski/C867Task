#pragma once
#include <string>;
#include "student.h";
using namespace std;

class Roster {

public:
	Student* classRosterArray[5]; //parse and add Students to this array
	Roster(); // Declare the constructor
	~Roster(); // Declare the destructor if it's not already there
	void add(string studentID, string firstName, string lastName,
		string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeprogram);

	void remove(string studentID);
	static DegreeProgram dpToString(string dp);
	void parse(string row);// parse studentData string array and create a student object with the data
	void printAll();
	void printAverageDaysInCourse(string StudentID);
	void printByDegreeProgram(DegreeProgram degree);
	void printInvalidEmails();
};

