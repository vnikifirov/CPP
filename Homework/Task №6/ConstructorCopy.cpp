#include <iostream>
#include <string>

using namespace std;

class CopyConstructor
{
private:
	string* name;
	int price;
public:
	CopyConstructor() : price(0) {
		name = new string;
	}

	CopyConstructor(string name, int price) {
		this->name = new string(name);
		this->price = price;
	}

	CopyConstructor(const CopyConstructor &copyingObj) {
		cout << "Copy constructor is colled" << endl;
		this->name = new string(*copyingObj.name);
		price = copyingObj.price;
	}

	~CopyConstructor() {
		delete name;
	}

	void change(string name, int price) {
		this->name = new string(name);
		this->price = price;
	}

	void show() {
		cout << "Name " << *name << " price $" << price << endl;
	}

	CopyConstructor& operator=(CopyConstructor& rethernceObj) {
		*(this->name) = *rethernceObj.name;
		price = rethernceObj.price;
		return *this;
	}
};

int main()
{
	CopyConstructor firstObj("Eloquent JavaScript", 25);
	firstObj.show();

	CopyConstructor secondObj;
	secondObj = firstObj;
	firstObj.change("C++ Primer Plus", 27);
	firstObj.show();

	cout << "Before recording" << endl;
	secondObj.show();

	system("pause");
	return 0;
}
