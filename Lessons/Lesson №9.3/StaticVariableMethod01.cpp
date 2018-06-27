#include <iostream>
#include <conio.h>
using namespace std;

class Count {
private:
	static int size;
	int ID;
public:
	Count() {
		size++;
		ID = size;
	}
	
	~Count() {
		size--;
	}

	static void showSize() {
		cout << size << endl;
	}

	void showID() {
		cout << ID << endl;
	}
};

int Count::size = 0;

int main() {
	Count firstObjl, secondObjl, threeObjl;
	Count::showSize();

	_getch();
}