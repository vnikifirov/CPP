#include <iostream>
#include <string>

using namespace std;

class Man {
protected:
	string name; // Create the pointer here.
public:
	void putName() {
		cout << "Enter name: ";
		cin >> name;
	}

	void getName() {
		cout << name << endl;
	}

	virtual void put() = 0;
	virtual bool goodMan() = 0;
};

class Student : public Man {
private:
	float average;
public:
	void put() {
		Man::putName();
		cout << "Enter average mark: ";
		cin >> average;
	}

	bool goodMan() {
		return ((average > 4) ? true : false);
	}
};

class Teacher : public Man {
private:
	int amountPublication;
public:
	void put() {
		Man::putName();
		cout << "Enter amount of the publication: ";
		cin >> amountPublication;
	}

	bool goodMan() {
		return ((amountPublication > 10) ? true : false);
	}

};