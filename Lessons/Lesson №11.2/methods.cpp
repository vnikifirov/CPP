#include "The_list.h"

// No-argument of Constructor
dLinkedList::dLinkedList() {
	firstPtr = nullptr;		// No frist link
}

// Constructor for three arguments
dLinkedList::dLinkedList(const std::string authorBook, const std::string titleBook, const unsigned int yearBook) {
	Link* newLink = new Link; // Make new link

	// Set the data variables
	newLink->data.authorBook = authorBook;
	newLink->data.titleBook = titleBook;
	newLink->data.yearBook = yearBook;
	
	// Set up pointers to point to whatever addresses
	newLink->prev = nullptr;
	newLink->next = firstPtr;
	newLink->prev = newLink;

	// "fristPtr" to point to the newLink 
	firstPtr = newLink;
}

// Destructor
dLinkedList::~dLinkedList() {
	delete firstPtr;
}

// Add data item
void dLinkedList::addList(const std::string authorBook, const std::string titleBook, const unsigned int yearBook) {
	Link* newLink = new Link; // Make new link

	// Set the data variables
	newLink->data.authorBook = authorBook;
	newLink->data.titleBook = titleBook;
	newLink->data.yearBook = yearBook;

	// Set up pointers to point to whatever addresses
	newLink->prev = nullptr;
	newLink->next = firstPtr;
	
	if (firstPtr != 0)
		firstPtr->prev = newLink;

	// "fristPtr" to point to the newLink 
	firstPtr = newLink;
}

// Create file otherwise record in it
bool dLinkedList::recordFile() {
	Link* curr;
	std::ofstream file;

	// Check to firstPtr is empty
	if (!firstPtr) return false;
	file.open("Books.txt");
	curr = firstPtr;

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
bool dLinkedList::rrecordFile() {
	Link *header, *curr, *next, *prev;
	std::ofstream file;

	// Check to file is empty
	if (!firstPtr) return false;
	file.open("Books.txt");

	header = firstPtr;
	curr = firstPtr;
	next = nullptr;
	prev = nullptr;

	// Reversed of linked list
	while (curr != 0) {
		next = curr->next;
		curr->next = curr->prev;
		prev = curr;
		curr = next;
	}
	header = prev;

	file << std::setw(20) << "Author" << std::setw(30) << "Title" << std::setw(15) << "Year" << std::endl;
	while (header != 0) {
		if (file.is_open()) {
			file << std::setw(20) << header->data.authorBook
				<< std::setw(30) << header->data.titleBook
				<< std::setw(15) << header->data.yearBook
				<< std::endl;
			header = header->next;
		}
	}

	file.close();
	return true;
}

// Remove whole from list
bool dLinkedList::removeList() {
	if (firstPtr == nullptr)
		return false;

	while(firstPtr->next != 0) {
		firstPtr = firstPtr->next;
		delete firstPtr->prev;
	}
	delete firstPtr;
	firstPtr = nullptr;
	return true;
}

// Remove of corently element
bool dLinkedList::removeElement() {
	if (firstPtr == nullptr)
		return false;
	else if (firstPtr->next) {
		firstPtr = firstPtr->next;
		delete firstPtr->prev;
	} else {
		delete firstPtr;
		firstPtr = nullptr;
	}
	return true;
}

// Selective removal
bool dLinkedList::removeSelective(std::string nameBooks) {
	if (firstPtr == nullptr) return false;
	else {
		Link* current = firstPtr, *tmp;
		while (current != 0) {
			if (current->data.titleBook == nameBooks) {
				if (current->next == 0 && current->prev == 0) {
					delete firstPtr;
					current = firstPtr = nullptr;
					break;
				} else if (current->prev == 0) {
					tmp = current;
					current = current->next;
					current->prev = nullptr;
					firstPtr = current;
					delete tmp;
					break;
				} else if (current->next == 0) {
					tmp = current;
					current = current->prev;
					current->next = nullptr;
					firstPtr = current;
					delete tmp;
					break;
				} else {
					tmp = current;
					current = current->prev;
					current->next = current->next->next;
					current->next->prev = current->next->prev->prev;
					firstPtr = current;
					delete tmp;
					tmp = nullptr;
					break;
				}
			} else
				current = current->next;
		}
	}

	if (firstPtr) {
		while (firstPtr->prev != 0)
			firstPtr = firstPtr->prev;
	}
	return true;
}