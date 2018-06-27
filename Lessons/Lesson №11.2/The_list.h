#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>

struct Book {
	std::string authorBook;
	std::string titleBook;
	unsigned int yearBook;
};

// One element of list
struct Link {
	Book data;		// Data item
	Link* next;		// Pointer to foward link
	Link* prev;		// Pointer to backward link
};

class dLinkedList {
private:
	Link* firstPtr;	// Pointer to first link
public:
	// No-argument constructor
	dLinkedList();

	// Overflow constructor
	dLinkedList(const std::string authorBook, const std::string titleBook, const unsigned int yearBook);

	// Destructor
	~dLinkedList();

	// Add data item
	void addList(const std::string authorBook, const std::string titleBook, const unsigned int yearBook);
	
	// Create a file and record into data
	bool recordFile();
	
	// Reversed of create a file and record
	bool rrecordFile();

	// Remove whole from list
	bool removeList();
	
	// Remove of corently element
	bool removeElement();

	// Selective removal
	bool removeSelective(std::string);
};