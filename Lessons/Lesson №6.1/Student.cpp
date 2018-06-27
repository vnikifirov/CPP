#include <iostream>
#include <string>

#include "Student.h"
#include "ArrayData.h"
#include "Man.h"

Student::Student() : Man(), access(false), averageScore(.0) {
	for (int i(0); i < M; i++)
		arr[i] = 0;
}

Student::Student(std::string firstName, std::string middelName, bool access, int sizeOfMarks) :
	Man(firstName, middelName) {
	this->access = access;
	averageScore = .0;

	for (int i(0); i < M; i++)
		arr[i] = 0;
}

void Student::push(int mark, int index) {
	try {
		if (mark <= 0 || index < 0)
			throw "Error - number must be not less than zero or equal zero !!!";
		arr[index] = mark;
	} catch (const char* str) {
		std::cerr << str << std::endl;
	}
}

void Student::getFullName() {
	Man::getFullName();
	std::cout << "Marks: ";

	for (int i(0); i < M; i++) {
		if (arr[i] == 0)
			break;
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void Student::showAverageScore() {
	double sum = 0;

	int i;
	for (i = 0; i < M; i++) {
		if (arr[i] == 0)
			break;
		sum += arr[i];
	}
	averageScore = sum / i;
	std::cout << "The average score - " << averageScore << std::endl;
}

void Student::showAccessSession() {
	std::cout << "Ready to the session: ";

	if (averageScore >= 3.0) {
		access = true;
		std::cout << "YES" << std::endl;
	} else {
		access = false;
		std::cout << "NO" << std::endl;
	}
}

	

