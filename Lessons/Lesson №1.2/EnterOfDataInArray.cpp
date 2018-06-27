#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int W = 10;

int main() {
	int myArray[W];

	for (short int i = 0; i < W; i++) {
		cout << "Enter " << i << endl;
		cin >> myArray[i];
	}

	for (short int i = 0; i < W; i++) {
		cout << myArray[i] << endl;
	}

	system("pause");
	return 0;
}