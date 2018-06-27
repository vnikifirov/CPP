#include "The_list.h"
#include <exception>

void addBook(dLinkedList&);

int main() {
	dLinkedList dLL;
	std::string choice;

	do {
		std::cout << std::setw(1) << "y" << std::setw(30) << "Add a book" << std::endl
			<< std::setw(2) << "rw" << std::setw(29) << "Remove a book" << std::endl
			<< std::setw(4) << "rw a" << std::setw(27) << "Remove all of list" << std::endl
			<< std::setw(1) << "q" << std::setw(30) << "Shutdown" << std::endl
			<< ">>> ";
		getline(std::cin, choice);
		std::system("CLS");

		if (choice == "y")
			addBook(dLL);
		else if (choice == "rw")
			dLL.removeElement();
		else if (choice == "rw a")
			dLL.removeList();
		else
			std::cerr << "Error unknown command"; // It's itresting place!
		std::cin.ignore();
	} while (choice != "q" || choice == "y");

	try {
		if (!dLL.rrecordFile())
			throw std::runtime_error("Recording isn't done");
		else
			std::cout << "Recording is done in the file" << std::endl;
	} catch (std::runtime_error obj) {
		std::cerr << obj.what() << std::endl;
	}

	_getch();
}

void addBook(dLinkedList& dLL) {
	std::string authorBook, titleBook;
	int yearBook = -1;

	std::cout << "Author name: ";
	getline(std::cin, authorBook);
	std::cout << "Book title: ";
	getline(std::cin, titleBook);
	std::cout << "Year of book: ";
	std::cin >> yearBook;

	if (yearBook <= 0) std::cerr << "Something went wrong" << std::endl;
	else {
		dLL.addList(authorBook, titleBook, yearBook);
		std::system("CLS");
	}
}