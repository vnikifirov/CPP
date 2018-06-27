#include <conio.h>
// #include <algorithm>

#include "CircularBuffer.h";

using namespace std;

int main() {
	const int capacity = 15;
	CircularBuffer myCirBuf(capacity);

	int count = 0; // For account of elements
	for (auto i = 0; i < myCirBuf.size() + 2; ++i) {
		myCirBuf.insert(i);
		++count;
	}

	cout << "Total elements was added: " << count << endl
		<< "List elements: ";
	myCirBuf.print();	
	cout << endl;

	_getch();
}