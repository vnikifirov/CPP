#include <iostream>

using namespace std;

class Steck {
protected:
	static const int SIZE = 3;
	int arr[SIZE];
	int topSteck;

public:
	Steck() : topSteck(-1) {}

	void push(int var) {
		arr[++topSteck] = var;
	}

	int pop() {
		return arr[topSteck--];
	}
};

class SaveSteck : public Steck {
public:
	void push(int var) {
		if (topSteck >= SIZE - 1) {
			cerr << "Overlow!" << endl;
			exit(1);
		}
		Steck::push(var);
	}

	int pop() {
		if (topSteck < 0) {
			cerr << "The array empty!" << endl;
			exit(1);
		}
		return Steck::pop();
	}

};

int main() {
	SaveSteck obj1;

	obj1.push(1);
	obj1.push(2);
	obj1.push(3);
	obj1.push(4);

	cout << obj1.pop() << endl;

	system("pause");
	return 0;
}