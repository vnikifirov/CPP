#pragma once
#include "Man.h"

class Teacher : public Man {
private:
	int amountPublications;
public:
	void put();
	bool goodMan();
};