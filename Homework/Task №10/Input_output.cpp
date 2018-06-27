#include <iostream>
#include <conio.h>
#include <fstream>
#include <memory>
#include <string>

void read_file(std::shared_ptr<char>&);

int main() {
	std::shared_ptr<char> english_morse;

	read_file(english_morse);

	_getch();
}

void read_file(std::shared_ptr<char>& english_morse) {
	std::string name_file = "Something.txt";
	std::ifstream file(name_file);
	unsigned int size = 0;
	
	char counting;
	while (!file.eof()) {
		file >> counting;
		size++;
	}

	file.clear();
	file.seekg(0);

	english_morse = std::make_shared<char>(size - 1);

	if (!file.is_open() || file.fail()) {
		std::cerr << "Unable to open file!" << std::endl;
		exit(1);
	}

	for (unsigned int i(0); i < size - 1; ++i) {
		file >> english_morse.get()[i];
	}

	english_morse.get()[size - 1] = '\0';
	std::cout << english_morse << std::endl;

	file.close();
}