#pragma once

#include <iostream>
#include <iterator>
#include <vector>

class Queue {
private:
	// Members function
	int *circ_buff; // Array with elements
	int size_array, // Size of array
		front,		// Point at frist element
		rear;		// Point at last elements 
	bool circle;	// Rov indicator
public:
	// Default constructor
	Queue();

	// Overfull constructor
	Queue(int);

	// Destructor
	~Queue();

	// Cheak to queue is empty or not
	bool is_empty() const;

	// Method insert
	void push_back(int);

	// Method return and remove of frist added element
	std::vector<int> pop_front();

	// Method of displaying value 
	void print() const;

	// Method return the frist added value
	int peek() const;

	// Method return the last added value
	int back() const;

	// Method return of defined size
	int size() const;
};