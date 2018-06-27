#pragma once

#include <string>
#include "Man.h"

class Student : public Man {
private:
	static const int M = 50;
protected:
	int arr[M];
	double averageScore;
	bool access;
public:
	Student();
	Student(std::string, std::string, bool, int);

	void push(int, int);
	void getFullName();
	void showAverageScore();
	void showAccessSession();
};