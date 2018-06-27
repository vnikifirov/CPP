#include <iostream>

using namespace std;

const int SIZE = 20;

int main() {
	char arr[SIZE]; // Array for some text.
	int lenStrLen;

	cout << "Enter string " << endl;

	cin.get(arr, SIZE); // Reading text, including space.
	lenStrLen = strlen(arr); // Reading length text and return its.

	for (int i(0); i < lenStrLen; i++) {
		if (arr[i] >= 97 && arr[i] <= 122) { // This is location letters.
			arr[i] = (int)arr[i] - 32; // a-z(lowerCase) transformation to A-Z(UpperCase). Difference between a-z and A-Z equal 32.
		}
	}
	cout << arr << endl;

	system("pause");
	return 0;
}