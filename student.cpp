#include "student.h"


void Student::print() {

	cout << "Student ID: " << this->getStudentID() 
		 << "     First Name: " << this->getFirstName()
		 << "     Last Name: " << getLastName()
	     << "     Email: " << this->getEmailAddress()
	     << "     Age: " << this->getAge()
	     << "     Days to complete courses: {" << daysToCompleteCourses[0] << ", "
	     << daysToCompleteCourses[1] << ", " << daysToCompleteCourses[2] << "}"
	     << "     Degree Program: " << degreeProgramToString(degreeProgram) << "\n";
}

// Constructor definition
Student::Student() {
}

Student::Student(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysToComplete[numOfCourses],
	DegreeProgram degreeProgram)
	: studentID(studentID), firstName(firstName), lastName(lastName),
	emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
	// Copy the daysToComplete array values
	for (int i = 0; i < numOfCourses; i++) {
		this->daysToCompleteCourses[i] = daysToComplete[i];
	}
}

// Destructor definition
Student::~Student() {}


//Getters
string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress()
{
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysToCompleteCourses() {
	return this->daysToCompleteCourses;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}


//Setters
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToCompleteCourses(int daysToCompleteCourses[]) {
	for (int i = 0; i < numOfCourses; i++) {
		this->daysToCompleteCourses[i] = daysToCompleteCourses[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


string Student::degreeProgramToString(DegreeProgram degreeProgram) {
	switch (degreeProgram) {
	case SECURITY:
		return "SECURITY";
	case NETWORK:
		return "NETWORK";
	case SOFTWARE:
		return "SOFTWARE";
	default:
		return "UNKNOWN";
	}
}
