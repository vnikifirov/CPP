#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <memory>
#include <stack>

// Data
struct Book {
	std::string authorBook;
	std::string titleBook;
	unsigned int yearBook;
};

// One element of list
struct Link {
	Book data;					// Data item
	std::shared_ptr<Link> next;	// Pointer to foward link
	std::shared_ptr<Link> prev;	// Pointer to backward link
};

class dLinked_list {
private:
	std::shared_ptr<Link> datum;	// Pointer to first link
public:
	// No-argument constructor
	dLinked_list();

	// Overflow constructor
	dLinked_list(const std::string authorBook, const std::string titleBook, const unsigned int yearBook);

	// Destructor
	~dLinked_list();

	// Add data item
	void insert(const std::string authorBook, const std::string titleBook, const unsigned int yearBook);

	// Create a file and record into data
	bool record();

	// Reversed of create a file and record
	bool reverse_record();

	// Remove whole from list
	bool remove_list();

	// Remove of corently element
	bool remove_element();

	// Selective removal
	bool remove_selective(std::string);

	// Return length of linked list
	int size_datum();
};