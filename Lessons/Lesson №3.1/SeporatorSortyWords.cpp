#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
const int M = 80, S = 40;

void SeparatorString(const char [], char [S][M]);
void sortingWords(char [S][M], int);

int main() {
	char arrWords[M], arrString[S][M];										// First array for words, second array for certain text.
	short int amountDelimiter = 0;											// The amount delimiter in the text.

	cin.getline(arrWords, M);												// The first argument this where to place, the second argument for amount symbols.
	for (int i(0); arrWords[i] != '\0'; i++) {
		if (arrWords[i] == ',' || arrWords[i] == '.') amountDelimiter++;
	}

	SeparatorString(arrWords, arrString);
	sortingWords(arrString, amountDelimiter);

	for (int i(0); i < amountDelimiter; i++) {
		cout << arrString[i] << endl;
	}

	system("pause");
	return 0;
}

void SeparatorString(const char words[], char string[S][M]) {
	for (int i(0), k(0), j(0); words[i] != '\0'; i++) {
		if (words[i] == ',' || words[i] == '.') {
			strncpy(string[k], words + j + (j != 0), i - j - (j != 0)); // strncpy(destptr, srcptr, num);
			string[k][i - j - (j != 0)] = '\0';
			k++;
			j = i;
		}
	}
}																		// The function strncpy(where string is copied / copied string / The maximum number of characters in the string to be copied).

void sortingWords(char arrString[S][M], int amountDelimetr) {
	char tmp[S];
	for (int i(0); i < amountDelimetr - 1; i++) {
		for (int j(i + 1); j < amountDelimetr; j++) {
			if (strcmp(arrString[i], arrString[j]) > 0) {				// strcmp(left argument, rigth argument). The return value if (str1 great than str2 to 1) else if (str1 equal than str2 to 0) else (str1 less than str2 to -1).  
				cout << strcmp(arrString[i], arrString[j]) << endl;
				strcpy(tmp, arrString[i]);								// This is function strcpy(destination, argument), where left argument is the destination for the right argument.
				strcpy(arrString[i], arrString[j]);
				strcpy(arrString[j], tmp);
			}
		}
	}
}