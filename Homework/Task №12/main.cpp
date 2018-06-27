#include "dLLSmartPtr.h"
#include <exception>

void addBook(dLinked_list&);
bool UI(dLinked_list&);

int main() {
	dLinked_list dLL;

	while (UI(dLL));

	try {
		if (!dLL.reverse_record())
			throw std::runtime_error("Recording isn't done");
		else
			std::cout << "Recording is done in the file" << std::endl;
	}
	catch (std::runtime_error obj) {
		std::cerr << obj.what() << std::endl;
	}

	_getch();
}

bool UI(dLinked_list& dLL) {
	std::string selectCommand, selectItem;

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
	}
	else if (selectCommand == "q")
		return false;
	else if (selectCommand == "rw")
		dLL.remove_element();
	else if (selectCommand == "rw a")
		dLL.remove_list();
	else if (selectCommand == "rw s") {
		std::cout << "Select an item" << std::endl << ">>> ";
		getline(std::cin, selectItem);
		dLL.remove_selective(selectItem);
	}
	else
		std::cerr << "Error unknown command" << std::endl;

	return true;
}

void addBook(dLinked_list& dLL) {
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
		dLL.insert(authorBook, titleBook, yearBook);
}