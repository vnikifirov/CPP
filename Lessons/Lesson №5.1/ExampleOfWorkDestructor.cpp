#include <iostream>

using namespace std;

class Counting {
private:
	int privateVar;

public:
	Counting() : protectedVar(0) {
		cout << "baseContructor\n" << endl;
	}

	Counting(int var1) : protectedVar(var1) {
		cout << "baseContructor1\n" << endl;
	}

	~Counting() {
		cout << "baseDestructor\n" << endl;
	}

	void show() {
		cout << protectedVar << endl;

		cout << privateVar << endl;
	}

	Counting operator++() {
		return Counting(++protectedVar);
	}

protected:
	int protectedVar;

};

class CountingChild : public Counting {
private:
	int list1;

public:
	CountingChild() : Counting() {
		cout << "countingChildConstructor\n" << endl;
	}

	CountingChild(int var) : Counting(var) {
		cout << "countingChildConstructor(1)\n" << endl;
	}

	~CountingChild() {
		cout << "countingChildDestrutor\n" << endl;
	}

	CountingChild operator--() {
		return CountingChild(--protectedVar);
	}

};

int main() {
	CountingChild childObj1, childObj2(1);
	Counting baseObj1, baseObj2;

	//++childObj1;
	//++baseObj2;

	//	childObj2 = --childObj1;
	baseObj1 = childObj2;

	childObj1.show();


	system("pause");
	return 0;
}