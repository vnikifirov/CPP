#pragma once
#include "Man.h"

class Student : public Man {
private:
	float average;
public:
	void put();
	bool goodMan();
};