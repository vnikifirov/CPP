#include <iostream>
#include <cstring>
#include <string>

#include "Teacher.h"
#include "Man.h"
#include "Student.h"

Teacher::Teacher() : Man(), workTime(0), rate(0), sLog(nullptr), size(0) {}

Teacher::Teacher(std::string firstName, std::string middleName, double workTime, double rate) : Man(firstName, middleName) {
	this->workTime = workTime;
	this->rate = rate;
	size = 0;
	sLog = nullptr;
}

Teacher::~Teacher() {
	delete[] sLog;
}

void Teacher::showMoney() {
	std::cout << "Salary per month: " << workTime * rate << std::endl;
}

void Teacher::push(Student tmp, int size) {
	Student* ptrCopy;
	if (size == 0)
		sLog = new Student[size + 1];
	else {
		ptrCopy = new Student[size + 1];

		for (int i(0); i < size; i++)
			ptrCopy[i] = sLog[i];

		delete[] sLog;
		sLog = new Student[size + 1];

		for (int i(0); i < size; i++)
			sLog[i] = ptrCopy[i];

		delete[] ptrCopy;
	}

	sLog[size] = tmp;
	this->size = size;
}

void Teacher::getAllStudents() {
	for (int i(0); i <= size; i++)
		sLog[i].getFullName();
}