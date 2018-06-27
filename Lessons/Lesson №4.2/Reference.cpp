#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	// input/ output / namespace.

using namespace std;

void multTwoNumbers(int&);

int main() {
	int number = 5;
	int& reference = number;

	multTwoNumbers(number);

	cout << number << endl;

	system("pause");
	return 0;
}

void multTwoNumbers(int& reference) {
	reference *= 2;
}