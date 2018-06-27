#include <iostream> // imput / output / namespace
#include <string> // Include STL class the string. 
#include <iomanip> // include setw().

using namespace std;

string changesOrderLetters(string);

int main() {
	string anyText = "Storytelling about some text.";
	int positionLetter = anyText.find("o");

	cout << "The third letter of text is: " << setw(5) << anyText.at(3) << endl << endl		// The display the third letters.
		<< "This index of the third letter: " << setw(2) << positionLetter << endl << endl	// It displays the index letters
		<< changesOrderLetters(anyText) << endl << endl;									// The transfer of a certain text.

	system("pause");
	return 0;
}

// It makes a mirror image of the text.
string changesOrderLetters(string getText) {
	int indexFirstLetter = 0;
	string tmp; // To sort algorithm.

	for (int i(0); i < getText.size(); i++) {
		if (getText[i] == ' ' || getText[i] == '.') {					/* if (getText[i] == ' ') */
			for (int j(i - 1), k(indexFirstLetter); j > k; j--, k++) {	/* for (int j(i - 1), k(0); j > ((i - indexFirstLetter) / 2); j--, k++) */
				tmp[0] = getText[j];
				getText[j] = getText[k];								/* getText[indexFirstLetter + k] */
				getText[k] = tmp[0];									/* getText[indexFirstLetter + k] = tmp[0]; */
			}
			indexFirstLetter = i + 1;									// To position of first letter.
		}
	}

	return getText;														// it will be return result.
}
