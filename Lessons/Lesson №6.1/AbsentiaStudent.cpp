#include <iostream>
#include <cstdlib>

#include "AbsentiaStudent.h"
#include "Student.h"

AbsentiaStudent::AbsentiaStudent() : Student(), money(0) {}
AbsentiaStudent::AbsentiaStudent(std::string firstName, std::string middelName, bool access, int sizeOfMarks, int priceOfEducation) : Student(firstName, middelName, access, sizeOfMarks) {
	this->money = priceOfEducation;
}

void AbsentiaStudent::showAccessSession() {
	std::cout << "Ready to the session: ";
	if ((money >= 50000 + rand() % 100000) && averageScore >= 3.0) {
		access = true;
		std::cout << "YES" << std::endl;
	} else {
		access = false;
		std::cout << "NO" << std::endl;
	}
}