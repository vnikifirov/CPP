#include <iostream>
#include <string>

using namespace std;

int main() {
	string someString;										// The "string" is array comprising some text.

	cout << "Enter something " << endl;

	getline(cin, someString);								// Reading text, including space.

	for (int i(0); i < someString.size(); i++) {
		if (someString[i] >= 97 && someString[i] <= 122) {	// This is location letters.
			someString[i] = (int)someString[i] - 32;		// a-z(lowerCase) transformation to A-Z(UpperCase). Difference between a-z and A-Z equal 32.
		}
	}

	cout << someString << endl;


	system("pause");
	return 0;
}