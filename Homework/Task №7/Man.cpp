#include <iostream>
#include <string>
#include "Man.h"

Man::Man() {
 	name = new std::string;
}

Man::~Man() {
	delete name;
}

void Man::putName() {
	std::cout << "Enter name: ";
	std::cin >> *name;
}

void Man::getName() {
	std::cout << *name << std::endl;
}
