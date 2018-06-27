#include "The_list.h"
#include <exception>

void addBook(dLinkedList&);

int main() {
	dLinkedList dLL;
	std::string selectCommand, selectItem;
	
	do {
		std::cout << std::setw(1) << "y" << std::setw(30) << "Add a book" << std::endl
			<< std::setw(2) << "rw" << std::setw(29) << "Remove a book" << std::endl
			<< std::setw(4) << "rw a" << std::setw(27) << "Remove all of list" << std::endl
			<< std::setw(1) << "rw s" << std::setw(27) << "Selective removal" << std::endl
			<< std::setw(1) << "q" << std::setw(30) << "Shutdown" << std::endl
			<< ">>> ";
		getline(std::cin, selectCommand);
		std::system("CLS");

		if (selectCommand == "y") {
			addBook(dLL);
			std::system("CLS");
		} else if (selectCommand == "q")
			break;
		else if (selectCommand == "rw")
			dLL.removeElement();
		else if (selectCommand == "rw a")
			dLL.removeList();
		else if (selectCommand == "rw s") {
			std::cout << "Select an item" << std::endl << ">>> ";
			getline(std::cin, selectItem);
			dLL.removeSelective(selectItem);
		} else
			std::cerr << "Error unknown command" << std::endl;
	} while (true);

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
	std::cin.ignore();

	if (yearBook <= 0)
		std::cerr << "Something went wrong" << std::endl;
	else
		dLL.addList(authorBook, titleBook, yearBook);
}