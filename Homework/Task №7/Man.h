#pragma once
#include <iostream>

class Man {
protected:
	std::string* name;
public:
	Man();
	~Man();
	void putName();
	void getName();

	virtual void put() =0;
	virtual bool goodMan() =0;
};