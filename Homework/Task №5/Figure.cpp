#include <iostream>
#include <iomanip>
#include "Figure.h"

using namespace std;

Figure::Figure() {
	*arrNum = size = top = 0;
}

Figure::Figure(int SIZE) {
	try {
		if (SIZE != 2)
			throw "Error lenght:";
		this->size = SIZE;
	}
	catch (const char* errLen) {
		cerr << errLen << setw(15) << SIZE << endl;
	}

	arrNum = new int[size];
	top = 0;
}

Figure::~Figure() {
	delete[] arrNum;
}

int *Figure::countArea(int* arrNum) {
	int *copy = new int[size + 1];

	for (int i(0); i < size; i++)
		copy[i] = arrNum[i];

	copy[size + 1] = copy[0] * copy[1];
	delete[] arrNum;

	for (int i(0); i < size; i++)
		arrNum[i] = copy[i];
	delete[] copy;

	return arrNum;
}

void Figure::pushSide(int num) {
	try {
		if (top == size)
			throw "Error overlow: ";
		arrNum[top++] = num;
	}
	catch (const char* errOverlow) {
		cerr << errOverlow << setw(14) << top << endl;
	}
}

void Figure::showArea() {
	arrNum = countArea(arrNum);
	cout << "| Area:" << setw(17)
		<< arrNum[3] << endl;
}

void Figure::showSide() {
	cout << "| Sides:" << setw(16);

	for (int i(0); i < size; i++)
		cout << arrNum[i] << setw(5);

	cout << endl;
}