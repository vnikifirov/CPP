#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	// input/ output / namespace.
#include <cstring> // For work with string.
#include <string> // Obj string.

using namespace std;

void countLetters(string&, int);

int main() {
	string allLetters = "";
	int amountLetters = 0;

	getline(cin, allLetters);
	system("CLS");

	countLetters(allLetters, amountLetters);

	system("pause");
	return 0;
}

void countLetters(string& allLetters, int amountLetters) {
	for (int i(0), j(0), g(0); i < allLetters.size(); i++) {
		if (allLetters[i] == allLetters[i + 1])
			amountLetters++;
		else {
			cout << allLetters[i] << amountLetters + 1 << endl;
			amountLetters = 0;
		}
	}

	return;
}