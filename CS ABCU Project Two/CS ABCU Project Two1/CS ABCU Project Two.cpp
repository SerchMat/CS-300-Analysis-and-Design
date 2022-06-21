//============================================================================
// Name        : CS ABCU Project Two.cpp
// Author      : Sergio Mateos
//============================================================================

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Global objects and variabls
struct Course {
	string courseNumber;
	string courseName;
	vector<string> coursePrereqs;
};
vector<Course> courses;

//Function to Load Data
void LoadDataStructure() {
	//Open file
	ifstream infile;
	infile.open("ABCU.txt");

	//Insert data into course
	if (infile.is_open()) {
		string line;
		//Read file
		while (getline(infile, line)) {
			vector <string> tokens;
			string token;
			stringstream ss(line);
			//Tokenize ','
			while (getline(ss, token, ',')) {
				tokens.push_back(token);
			}
			//Create new Course and add it
			Course newCourse = Course();
			newCourse.courseNumber = tokens[0];
			newCourse.courseName = tokens[1];
			//If prerequiste exist
			if (tokens.size() > 2) {
				//For-Loop to look in prerequisites
				for (int i = 2; i < tokens.size(); i++) {
					//Add it to Course
					newCourse.coursePrereqs.push_back(tokens[i]);
				}
			}
			//Add new course to courses
			courses.push_back(newCourse);
		}
		//Verification message that the ABCU.txt is loaded
		cout << "Data Structure successfully loaded!" << endl;
	}
	system("PAUSE");
	//Close the file
	infile.close();
}

//Function to Print Course List
void PrintCourseList() {
	//Check if the sata is loaded in file
	if (courses.size() > 0) {
		//Sort courses in alphanumerically
		//For-loop to search in the course list
		for (int i = 0; i < courses.size() - 1; i++) {
			for (int j = 0; j < courses.size() - i - 1; j++) {
				//If the number of course is higher than the next course
				if (courses[j].courseNumber > courses[j + 1].courseNumber) {
					//Swapp courses
					swap(courses[j + 1], courses[j]);
				}
			}
		}
		//Print the Courses List
		cout << endl;
		cout << "Courses List" << endl;
		cout << endl;
		//For-Loop to print course number and name
		for (int i = 0; i < courses.size(); i++) {
			cout << courses[i].courseNumber << ", ";
			cout << courses[i].courseName << endl;
		}
		cout << endl;
	}
	//Else if ABCU.txt hasn't been loaded
	else {
		cout << "Error: Load Data Structure first." << endl;
		system("PAUSE");
	}
}

//Function to print Course
void PrintCourse() {
	//Check if the sata is loaded in file
	if (courses.size() > 0) {

		string courseInput;
		int courseFound = 0;
		//Ask for the course
		cout << "What course do you want to know about? (COURSE### Capital Letters) ";
		cin >> courseInput;
		cout << endl;

		//For-Loop to match courseInput in courseList
		for (int i = 0; i < courses.size(); i++) {
			//If there is a match
			if (courses[i].courseNumber == courseInput) {
				//Print information
				cout << "Course Information" << endl;
				cout << courses[i].courseNumber << ", ";
				cout << courses[i].courseName << endl;
				//Print Prerequisites
				cout << "Prerequisites: ";
				//If course has Prerequisites
				if (courses[i].coursePrereqs.size() > 0) {
					int prereqSize = courses[i].coursePrereqs.size();
					//For-Loop to look for prerequisites
					for (int j = 0; j < prereqSize - 1; j++) {
						//Print Prerequisites
						cout << courses[i].coursePrereqs[j] << ", ";
					}
					//Delete comm
					cout << courses[i].coursePrereqs[prereqSize - 1];
					courseFound = 1;
				}
				//If there is no Prerequisites
				else {
					//Print None
					cout << "None";
				}
				cout << endl;
			}
		}
		//if the input is not valid
		if (courseFound == 0) {
			//Print Error
			cout << "Error: Invalid Course" << endl;
			system("PAUSE");
		}
	}
	//Else if ABCU.txt hasn't been loaded
	else {
		cout << "Error: Load Data Structure first." << endl;
		system("PAUSE");
	}
}

//Main
int main() {
	bool quit = false;

	cout << endl;
	cout << "Welcome to the course planner." << endl;

	do {
		int option;

		//Menu
		cout << endl;
		cout << "  1. Load Data Structure" << endl;
		cout << "  2. Print Course List" << endl;
		cout << "  3. Print Course" << endl;
		cout << "  9. Exit" << endl;
		cout << endl;
		cout << "What would you like to do? ";
		cin >> option;
		cout << endl;

		//Verify that the input is valid
		while ((option != 1) && (option != 2) && (option != 3) && (option != 9)) {
			cout << "Error: " << option << " is not a valid option." << endl;
			system("PAUSE");
			//Menu ste up
			cout << endl;
			cout << "  1. Load Data Structure" << endl;
			cout << "  2. Print Course List" << endl;
			cout << "  3. Print Course" << endl;
			cout << "  9. Exit" << endl;
			cout << endl;
			cout << "What would you like to do? ";
			cin >> option;
			cout << endl;
		}
		//Switch tonavigate throu the Menu
		switch (option) {
		case 1:
			LoadDataStructure();
			break;
		case 2: 
			PrintCourseList();
			break;		
		case 3:
			PrintCourse();
			break;
		case 9:
			cout << "Thank you for using the course planner!" << endl;
			break;
		default:
			cout << "Invalid input" << endl;
		}
	} while (!quit);

	return 0;
}
