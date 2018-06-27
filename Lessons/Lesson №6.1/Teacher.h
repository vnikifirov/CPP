#pragma once

#include <string>

#include "Man.h"
#include "Student.h"

class Teacher : public Man {
private:
	int size;
	double workTime;
	double rate;
	Student* sLog;
public:
	Teacher();
	Teacher(std::string, std::string, double, double);
	~Teacher();

	void showMoney();
	void push(Student, int);
	void getAllStudents();
};