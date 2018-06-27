#pragma once

#include <string>

class Man {
protected:
	std::string firstName, middleName;
public:
	Man();
	Man(std::string, std::string);

	void getFullName();
};
