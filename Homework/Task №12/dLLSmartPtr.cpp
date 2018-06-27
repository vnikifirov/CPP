#include "dLLSmartPtr.h"

// No-argument of Constructor
dLinked_list::dLinked_list() : datum(nullptr) {}

// Constructor for three arguments
dLinked_list::dLinked_list(const std::string authorBook, const std::string titleBook, const unsigned int yearBook) {
	std::shared_ptr<Link> newLink = std::make_shared<Link>(); // Make new link

	// Set the data variables
	newLink->data.authorBook = authorBook;
	newLink->data.titleBook = titleBook;
	newLink->data.yearBook = yearBook;

	// Set up pointers to point to whatever addresses
	newLink->next = datum;
	newLink->prev = newLink;

	// "fristPtr" to point to the newLink 
	datum = newLink;
}

// Destructor
dLinked_list::~dLinked_list() {
	std::cout << "List destructor invoked" << std::endl;
}

// Add data item
void dLinked_list::insert(const std::string authorBook, const std::string titleBook, const unsigned int yearBook) {
	std::shared_ptr<Link> newLink = std::make_shared<Link>(); // Make new link

	// Set the data variables
	newLink->data.authorBook = authorBook;
	newLink->data.titleBook = titleBook;
	newLink->data.yearBook = yearBook;

	// Set up pointers to point to whatever addresses
	newLink->next = datum;

	if (datum != 0)
		datum->prev = newLink;

	// "fristPtr" to point to the newLink 
	datum = newLink;
}

// Create file otherwise record in it
bool dLinked_list::record() {
	std::shared_ptr<Link> curr;
	std::ofstream file;

	// Check to firstPtr is empty
	if (!datum) return false;
	file.open("Books.txt");
	curr = datum;

	if (file.is_open()) {
		file << std::setw(20) << "Author" << std::setw(30) << "Title" << std::setw(15) << "Year" << std::endl;
		while (curr != 0) {
			file << std::setw(20) << curr->data.authorBook
				<< std::setw(30) << curr->data.titleBook
				<< std::setw(15) << curr->data.yearBook
				<< std::endl;
			curr = curr->next;
		}

		file.close();
		return true;
	}
}

// Reversed of create file otherwise record in it
bool dLinked_list::reverse_record() {
	std::stack<std::shared_ptr<Link>> reverse_firstPtr;
	std::ofstream file;

	// Check to file is empty
	if (!datum) return false;
	file.open("Books.txt");

	// Reversed of linked list
	while (datum != 0) {
		reverse_firstPtr.push(datum);
		datum = datum->next;
	}

	// Recording of linked list
	file << std::setw(20) << "Author" << std::setw(30) << "Title" << std::setw(15) << "Year" << std::endl;
	while (!reverse_firstPtr.empty()) {
		if (file.is_open()) {
			file << std::setw(20) << (reverse_firstPtr.top())->data.authorBook
				<< std::setw(30) << (reverse_firstPtr.top())->data.titleBook
				<< std::setw(15) << (reverse_firstPtr.top())->data.yearBook
				<< std::endl;
			reverse_firstPtr.pop();
		}
	}

	file.close();
	return true;
}

// Remove whole from list
bool dLinked_list::remove_list() {
	if (datum == nullptr)
		return false;
	else {
		while (datum->next != 0) {
			datum = datum->next;
			datum->prev.reset();
		}
		datum.reset();
	}
	return true;
}

// Remove of corently element
bool dLinked_list::remove_element() {	
	if (datum == nullptr)
		return false;
	else if (datum->next) {
		datum = datum->next;
		datum->prev = nullptr;
	} else
		datum.reset();
	return true;
}

// Selective removal
bool dLinked_list::remove_selective(std::string nameBooks) {
	if (datum == nullptr) return false;
	else {
		std::shared_ptr<Link> current = datum;
		while (current != 0) {
			if (current->data.titleBook == nameBooks) {
				if (current->next == 0 && current->prev == 0) {
					datum.reset();
					break;
				}
				else if (current->prev == 0) {
					current = current->next;
					current->prev = nullptr;
					datum = current;
					break;
				}
				else if (current->next == 0) {
					current = current->prev;
					current->next = nullptr;
					datum = current;
					break;
				}
				else {
					current = current->prev;
					current->next = current->next->next;
					current->next->next->prev = current;
					datum = current;
					break;
				}
			} else
				current = current->next;
		}
	}

	if (datum) {
		while (datum->prev != 0)
			datum = datum->prev;
	}
	return true;
}

// Return length of linked list
int dLinked_list::size_datum() {
	int size = 0;

	while (datum != nullptr) {
		datum->next;
		++size;
	}

	return size;
}