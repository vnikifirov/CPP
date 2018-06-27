#include <iostream>
#include <string>

#include "Man.h"

Man::Man() {
	firstName = ' ';
	middleName = ' ';
}

Man::Man(std::string firstName, std::string middleName) {
	this->firstName = firstName;
	this->middleName = middleName;
}

void Man::getFullName() {
	std::cout << "Full name: " << firstName << ' ' << middleName << std::endl;
}

