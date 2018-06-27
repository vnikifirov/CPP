#define _CRT_SECURE_NO_WARNINGS // ???
#include <iostream> // output / input / namespace.
#include <cstdlib> // Math rond.

using namespace std; // space name.

const int H = 10;

int tmp; // For sorting algorithm.
int arraySomeNum[H]; // Array with element.
int minElementArr; // Here minimum element array will be story.

void createArray() {
	for (int i(H); i > 0; i--) {
		arraySomeNum[i] = rand() % 10;
	}
}

// We looking of minimum element array.
void searchMinElement() {
	minElementArr = arraySomeNum[0];
	for (int i(H - 1); i >= 0; i--) {
		if (arraySomeNum[i] > minElementArr) {
			minElementArr = arraySomeNum[i];
		}
	}
	cout << "Minimum element: " << minElementArr << endl;
}

// Sorting array on type buble.
void sortingBuble() {
	for (int i(H), j(0); i > 0; i--, j++) {
		if (arraySomeNum[j] > arraySomeNum[i]) {
			tmp = arraySomeNum[i];
			arraySomeNum[i] = arraySomeNum[j];
			arraySomeNum[j] = tmp;
		}
	}
}

// Display array on the screen.
void displayArray() {
	cout << "Some array: ";

	for (int i(0); i < H; i++) {
		cout << arraySomeNum[i] << ' ';
	}
	cout << endl;
}

int main() {
	createArray();
	searchMinElement();
	sortingBuble();
	displayArray();

	system("pause");
	return 0;
}