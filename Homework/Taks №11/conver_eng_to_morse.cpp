#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iterator>

bool loadFile(std::vector<std::vector<std::string>>&);
bool getWords(std::string&);
std::string convertMorse(std::vector<std::vector<std::string>>&, std::string&);

int main() {
	std::vector<std::vector<std::string>> vocabulary;
	std::string userStr;

	if (loadFile(vocabulary))
		std::cout << "File was copied completely" << std::endl;
	else
		std::cerr << "Unable to copy the file correctly!" << std::endl;
	if (!getWords(userStr)) std::cout << "Cancel" << std::endl;

	std::cout << convertMorse(vocabulary, userStr) << std::endl;

	_getch();
}

bool loadFile(std::vector<std::vector<std::string>>& vocabulary) {
	std::ifstream inFile("english_morse_alphabet.txt", std::ios::in);

	// Try to open file
	if (!inFile.is_open()) {
		return false;
	}

	while (!inFile.eof()) {
		// Members of loop
		std::vector<std::string> symbols;
		std::string letter, standsFor;
	
		inFile >> letter;
		std::getline(inFile, standsFor);
		// Remove symbol tabulation 
		standsFor.erase(std::remove(standsFor.begin(),
			standsFor.end(), '\t'), standsFor.end());
		symbols.push_back(letter);
		symbols.push_back(standsFor);
		vocabulary.push_back(symbols);
	}

	return true;
}

bool getWords(std::string& userStr) {
	std::cout << "What do you want to convert to morse code? (n/N)" << std::endl;
	std::getline(std::cin, userStr);
	
	if (userStr == "n" || userStr == "N") return false;
	return true;
}

std::string convertMorse(std::vector<std::vector<std::string>>& vocabulary, std::string& userStr) {
	std::string codeMorse;

	std::transform(userStr.cbegin(), userStr.cend(), userStr.begin(), toupper);
//	std::for_each(userStr.cbegin(), userStr.cend(), toupper);

	for (int j(0); j < userStr.size(); ++j) {
		for (int i(0), k(0); i < vocabulary.size(); ++i) {
			std::string str;
			str.push_back(userStr[j]);
			if (vocabulary[i][k] == str) {
				codeMorse += vocabulary[i][++k];
				codeMorse.push_back(' ');
				break;
			}

			if (userStr[j] == ' ') {
				codeMorse.push_back('/');
				break;
			}
		}
	}

	return codeMorse;

	// std::vector<std::vector<std::string>>::iterator it;
	// for (it = vocabulary.begin(); it != vocabulary.end(); ++it) {}
	// var = std::find(var.begin(), var.end(), where_search);
	// var::toupper
}