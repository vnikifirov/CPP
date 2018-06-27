#include <iostream>
#include <conio.h>
using namespace std;

class parentFirst {
public:
	static const int var{};
	void show() {
		cout << "Parent first" << endl;
	}
};

class parentSecond {
public:
	void show() {
		cout << "Parent second" << endl;
	}
};

class ChildFirst : virtual public parentFirst {};
class ChildSecond : virtual public parentFirst {};
class babySign : public ChildFirst, public ChildSecond {};

//class Child : public parentFirst, public parentSecond {};

int main() {
	//Child objSign;
	//objSign.parentFirst::show();
	babySign objSign;
	objSign.show();

	_getch();
}
