#pragma once

#include <string>
#include "Student.h"

class AbsentiaStudent : public Student {
private:
	int money;
public:
	AbsentiaStudent();
	AbsentiaStudent(std::string, std::string, bool, int, int);

	void showAccessSession();
};