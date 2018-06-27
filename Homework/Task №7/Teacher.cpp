#include "Teacher.h"

void Teacher::put() {
	Man::putName();
	std::cout << "Enter amount of the publication: ";
	std::cin >> amountPublications;
}

bool Teacher::goodMan() {
	return ((amountPublications > 10) ? true : false);
}