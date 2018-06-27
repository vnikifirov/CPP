/*//////////////////////TASK///////////////////////
1) Data output into a single string				///
2) With spaces.									///
3) Use a string object.							///
4) No point.									///
*//////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	// input/ output / namespace.
#include <cstring> // For work with string.
#include <string> // Obj string.

using namespace std;

int countDelimiter(string*, int);											// Prototype of the function.
string **separatorString(const string*, string**);							// Prototype of the function.
string **sortingWords(string**, int);										// Prototype of the function.

int main() {
	int H = 250, W = 250;													// Size array.
	short int amountDelimiter = 0;											// Created a variable for the number of delimiter.
	string userText;														// Created array for words.
	string *ptrUserText = &userText;										// Created the pointer to array words.
	string **arrStr = new string*[H];										// Created pointer to arr pointers, type string.

	for (int i(0); i < W; i++)
		arrStr[i] = new string[W];											// Creating pointer to arr pointers (create matrix or table). 	

	cout << "Enter your text : ";
	getline(cin, (*ptrUserText));											// Dereferencing pointer and get value in string.
	system("CLS");															// Cleaning the screen.

	amountDelimiter = countDelimiter(ptrUserText, amountDelimiter);			// Counting delimiter.
	arrStr = separatorString(ptrUserText, arrStr);							// Split into words.
	arrStr = sortingWords(arrStr, amountDelimiter);							// Sorting words.

	cout << "Source string : " << (*ptrUserText) << endl;
	cout << "Delimiters in the string: " << amountDelimiter << endl;
	cout << "Words: " << amountDelimiter << endl;
	for (int i(0); i < amountDelimiter; i++)								// Display result.
		cout << *(arrStr[i]) << endl;

	for (int i(0); i < W; i++)												// Freeing memory for the string.
		delete[] arrStr[i];
	delete[] arrStr;														// Freeing memory for the array pointers.

	system("pause");
	return 0;
}

int countDelimiter(string *arrWords, int amountDelimiter) {
	for (int i(0); i < (*arrWords).size(); i++)								// Searching delimiter.
		if ((*arrWords)[i] == ',' || (*arrWords)[i] == '.')					// Dereferencing pointer and compare.
			amountDelimiter++;

	return amountDelimiter;
}

string **separatorString(const string *arrWords, string **arrStr) {
	for (int i(0), j(0), k(0); i < (*arrWords).size(); i++) {
		if ((*arrWords)[i] == ',' || (*arrWords)[i] == '.') {				// Conditional test.
			if ((i + 1 == (*arrWords).size()) && (*arrWords)[i] == '.')
				*(arrStr[j]) = (*arrWords).substr(k + +(k != 0) * 2, i - k - +(k != 0) * 2); // An issue if string has a space after delimiter that need to +3 or +(k != 0)  * 3
			else
				*(arrStr[j]) = (*arrWords).substr(k + +(k != 0) * 2, i - k - +(k != 0));
			k = i;
			j++;
		}
	}

	return arrStr;
}

string **sortingWords(string **arrStr, int amountDelimetr) {
	for (int i(0); i < amountDelimetr - 1; i++) {
		for (int j(i + 1); j < amountDelimetr; j++) {
			if (*arrStr[i] < *arrStr[j]) {									// Dereferencing pointer and compare string.
				(*arrStr[i]).swap((*arrStr[j]));							// Changes a string seats.
			}
		}
	}

	return arrStr;
}