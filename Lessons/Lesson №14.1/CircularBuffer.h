#pragma once

#include <iostream>
#include <iterator>

// Circular buffer
class CircularBuffer {
private:
	// Members function
	int *circ_buff;
	int size_array,
		top;
public:
	// Default constructor
	CircularBuffer();

	// Overfull constructor
	CircularBuffer(int);

	// Destructor
	~CircularBuffer();

	// Method insert
	void insert(int);

	// Method of displaying value 
	void print() const;

	// Method return of defined size
	int size() const;
};