#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct Student {
	string name;
	int age;
	bool scholarship;
};

void printStudents(Student* students, int numberOfStudent) {
	int numberWantedStudent;
	cout << "Data from struct: " << endl;
	for (int i = 0; i < numberOfStudent; i++) {
		cout << "Number: " << i + 1 << " name: " << students[i].name << " age: " << students[i].age << " scholarship: " << students[i].scholarship << endl;
	}
	string line;
	fstream fileWithStudentInformation;
	fileWithStudentInformation.open("file.txt", ios::in);
	if (!fileWithStudentInformation.is_open()) {
		cout << "File isn't open!" << endl;
		return;
	}
	cout << "Data from file: " << endl;
	while (getline(fileWithStudentInformation, line)) {
		cout << line << endl;
	};
	fileWithStudentInformation.close();
	fileWithStudentInformation.open("file.txt", ios::in);
	if (!fileWithStudentInformation.is_open()) {
		cout << "File isn't open!" << endl;
		return;
	}
	printf("%s \n", "Enter number of student, who you want to get");
	cin >> numberOfStudent;
	while (getline(fileWithStudentInformation, line)) {
		string strForSearching(1, line[0]);
		if (strForSearching == to_string(numberOfStudent)) {
			cout << line << endl;
			break;
		}
	};
	fileWithStudentInformation.close();
}

void enterStudents(Student* &students, int numberOfStudent) {
	int number;
	fstream fileWithStudentInformation;
	fileWithStudentInformation.open("file.txt", ios::out);
	if (!fileWithStudentInformation.is_open()) {
		cout << "File isn't open!" << endl;
		return;
	}
	students = new Student[numberOfStudent];
	for (int i = 0; i < numberOfStudent; i++) {
		number = i + 1;
		printf("%s \n", "Enter student name: ");
		cin >> students[i].name;
		fileWithStudentInformation << number << " ";
		fileWithStudentInformation << students[i].name << " ";
		cout << endl;
		printf("%s \n", "Enter student age: ");
		cin >> students[i].age;
		fileWithStudentInformation << students[i].age << " ";
		cout << endl;
		printf("%s \n", "Have is student scholarship? (Yes/No): ");
		cin >> students[i].scholarship;
		fileWithStudentInformation << students[i].scholarship << endl;
		cout << endl;
	}
	fileWithStudentInformation.close();
	printStudents(students, numberOfStudent);
}

void fileForVariablesIn() {
	int id;
	string name;
	float balance;
	fstream fileForManipulationsIn;
	fileForManipulationsIn.open("file_for_inout", ios::in);
	if (!fileForManipulationsIn.is_open()) {
		cout << "Your file isn't open! Error" << endl;
	}
	else {
		fileForManipulationsIn >> balance;
		fileForManipulationsIn >> id;
		fileForManipulationsIn >> name;

		cout << "name: " << name << endl;
		cout << "balance: " << balance << endl;
		printf("Id: %d, name: %s, balance: %.2f", id, name.c_str(), balance);
		fileForManipulationsIn.close();
	}
}

void fileForVariablesOut() {
	int id = 11;
	string name = "Ivan";
	float balance = 1250.5;
	printf("%s", "Enter your name:");
	cin >> name;
	cout << endl;
	printf("%s", "Enter your id:");
	cin >> id;
	cout << endl;
	printf("%s", "Enter your balance:");
	cin >> balance;
	cout << endl;
	
	
	fstream fileForManipulationsOut;
	fileForManipulationsOut.open("file_for_inout", ios::out);
	if (!fileForManipulationsOut.is_open()) {
		cout << "Your file isn't open! Error" << endl;
	}
	else {
		cout << "All is OK" << endl;
		fileForManipulationsOut << balance << endl;
		fileForManipulationsOut << id << endl;
		fileForManipulationsOut << name << endl;
		
		fileForManipulationsOut.close();
	}
	fileForVariablesIn();
}


void Choice() {
	printf("%s \n", "Enter yout choice: z - variables, f - line in file");
	char key = _getch();
	if (key == 'z') {
		fileForVariablesOut();
	}
	else if (key == 'f') {
		cout << "f is choicen" << endl;
		int studNumber;
		Student* students = nullptr;
		cout << "Enter number of students: ";
		cin >> studNumber;
		enterStudents(students, studNumber);
	}
	else {
		system("cls");
		Choice();
	}
}

int main() {

	Choice();

	return 0;
}
