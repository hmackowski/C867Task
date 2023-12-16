#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

int main()
{
	Roster classRoster;
	Student student;
	cout << "C867-Scripting and Programming: Applications\nLanguage: C++\nWGU Student ID: 011241928 \nName: Haskell Mackowski\n\n";

	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Haskell,Mackowski,hmacko6@wgu.edu,38,21,20,5,SOFTWARE" };

	cout << "Student Data:\n";
	for (string student : studentData) {
		classRoster.parse(student);
	}
	
	classRoster.printAll();

	classRoster.printInvalidEmails();



	cout << "Average days in three courses:" << endl;
	for (int i = 0; i < 5; i++){
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	cout << endl << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");
	cout << endl << endl;

	classRoster.printAll();

	classRoster.remove("A3");











} 

