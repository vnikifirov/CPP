#include <iostream>
#include <iomanip> // For setw.

#include "ArrayData.h"

ArrayData::ArrayData() {
	stackPtr = 0;
	size = top = lenght = 0;
}

ArrayData::ArrayData(int maxSize) {
	try {
		if (maxSize < 0)
			throw "Error - number must be not less than zero !!!";
		size = maxSize;
		stackPtr = new int[size];
		top = lenght = 0;
	} catch (const char* str) {
		std::cerr << str << std::endl;
	}
}

ArrayData::~ArrayData() {
	delete[] stackPtr;
}

void ArrayData::push(int number) {
	try {
		if (top >= size)
			throw "Error - overflow !!!";
		stackPtr[top++] = number;
		lenght = top;
	} catch (const char* str) {
		std::cerr << str << std::endl;
	}
}

void ArrayData::print() {
	while (top > 0)
		std::cout << stackPtr[--top] << std::setw(2);
}

int ArrayData::showArr() {
	int lenCopy = lenght;
	return stackPtr[--lenCopy];
}
