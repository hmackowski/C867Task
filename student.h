#pragma once
#include "degree.h";
#include <string>;
#include <iostream>
using namespace std;

class Student {
public:
	const int static numOfCourses = 3;
private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteCourses[numOfCourses];
	DegreeProgram degreeProgram;

public:
	// Constructor declaration
	Student(string studentID, string firstName, string lastName,
		string emailAddress, int age, int daysToCompleteCourses[numOfCourses],
		DegreeProgram degreeProgram);
	Student();
	// Destructor declaration
	~Student();

public:

	void print();
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToCompleteCourses();
	DegreeProgram getDegreeProgram();
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToCompleteCourses(int daysToCompleteCourses[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	string degreeProgramToString(DegreeProgram degreeProgram);
};

