#include "roster.h"
#include <sstream>
#include <iostream>

// Declare the classRosterArray as an array of Student pointers
Student* classRosterArray[5]; // Specify the size of the array

Roster::Roster() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		classRosterArray[i] = nullptr;
	}
}
// Adds a new student to the roster
void Roster::add(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName,
				emailAddress, age, days, degreeprogram);
			return;
		}
	}
}

// Removes a student from the roster by their student ID
void Roster::remove(string studentID) {
	bool found = false;
	cout << "\n\nAttempting to remove student: " << studentID;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			found = true;
			cout << "\nAttempt to remove student: " << studentID << "  was successful.";
			break;
		}
		
	}
	if (!found) {
		cout << "\nError: Student ID " << studentID << " not found." << endl;
	}
	
}

// Parses a single row of student data
void Roster::parse(string studentDataRow) {
	// Existing implementation
	string studentID, firstName, lastName, emailAddress, ageString,
		daysInCourse1String, daysInCourse2String, daysInCourse3String, degreeProgram;

	stringstream ss(studentDataRow);
	getline(ss, studentID, ',');
	getline(ss, firstName, ',');
	getline(ss, lastName, ',');
	getline(ss, emailAddress, ',');
	getline(ss, ageString, ',');
	getline(ss, daysInCourse1String, ',');
	getline(ss, daysInCourse2String, ',');
	getline(ss, daysInCourse3String, ',');
	getline(ss, degreeProgram, ',');

	DegreeProgram degree = dpToString(degreeProgram);

	int age = stoi(ageString);
	int daysInCourse1 = stoi(daysInCourse1String);
	int daysInCourse2 = stoi(daysInCourse2String);
	int daysInCourse3 = stoi(daysInCourse3String);

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

DegreeProgram Roster::dpToString(string dp) {
	// Existing implementation
	if (dp == "SECURITY") return SECURITY;
	if (dp == "SOFTWARE") return SOFTWARE;
	if (dp == "NETWORK") return NETWORK;
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

// Destructor to release memory
Roster::~Roster() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}



void Roster::printByDegreeProgram(DegreeProgram degree) {
	cout << "Students by Degree = SOFTWARE" << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) { // Check for null pointer
			DegreeProgram degreeInArray = classRosterArray[i]->getDegreeProgram();
			if (degreeInArray == degree) {
				classRosterArray[i]->print();
			}
		}
	}
}


void Roster::printInvalidEmails() {
	bool emailError = false;
	cout << "\n\nInvalid Emails:\n";
	for (int i = 0; i < 5; ++i) {
		string emailAddress = (classRosterArray[i]->getEmailAddress());

		if (emailAddress.find("@") == string::npos ||
			(emailAddress.find('.') == string::npos) ||
			(emailAddress.find(' ') != string::npos)) {
			emailError = true;
			cout << emailAddress << ": " << classRosterArray[i]->getEmailAddress() << std::endl;
		}
	}
	cout << std::endl << std::endl;
}

void Roster::printAverageDaysInCourse(string StudentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == StudentID) {
			int averageDays = (classRosterArray[i]->getDaysToCompleteCourses()[0] +
				classRosterArray[i]->getDaysToCompleteCourses()[1] +
				classRosterArray[i]->getDaysToCompleteCourses()[2]) / 3;

			cout << "StudentID: " << StudentID << ", is averaging " << averageDays << " days in their courses." << endl;
			return;
		}
	}

	cout << "Student ID " << StudentID << " not found." << endl;
}
