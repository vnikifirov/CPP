#include "Student.h"

void Student::put() {
	Man::putName();
	std::cout << "Enter average mark: ";
	std::cin >> average;
}

bool Student::goodMan() {
	return ((average > 3.5) ? true : false);
}
