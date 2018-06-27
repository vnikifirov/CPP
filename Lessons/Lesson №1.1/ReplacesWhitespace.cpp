#define _CRT_SECURE_NO_WARNINGS // ???
#include <iostream> // output / input / namespace.
#include <stdio.h> // ???

using namespace std;

const int W = 80;
const int H = 10;

void delBlank(char useStr[]) {
	char ArrWithoutSpace[W] = ""; // Create array of the size eighty with ???
	int lenStr; // Storage for measurement of length string.
	int lenStrSource = strlen(useStr); // Measurement of length string.

	for (int i(0), j(0); i < lenStrSource; i++) {
		if (useStr[i] == ' ') {
			if (j == 0) continue; // For first char.
			if (useStr[i + 1] == ' ') continue;
		}
		ArrWithoutSpace[j] = useStr[i];
		j++;
	}

	lenStr = strlen(ArrWithoutSpace); // Measurement of length string.

	if (ArrWithoutSpace[lenStr - 1] == ' ') {
		ArrWithoutSpace[lenStr - 1] = '\0'; // This "Byte zero".
	}

	cout << ArrWithoutSpace << endl; // Display of an array on the screen.
}

int main() {
	char userStr[H][W]; // Array for some text.

	for (int i = 0; i < H; i++) {
		cout << "Enter " << i << " string" << endl; // Enter a some text.
		gets_s(userStr[i]); // ???
	}

	for (int i = 0; i < H; i++) {
		cout << userStr[i] << endl; // Output data.
		delBlank(userStr[i]); // Remove extra spaces.
	}

	system("pause"); // Stop system.

	return 0;
}