#include "CircularBuffer.h"

// Default constructor for five elements
CircularBuffer::CircularBuffer() : size_array(5) {
	circ_buff = new int[size_array];
}

// Overfull constructor
CircularBuffer::CircularBuffer(int size) : size_array(size) {
	circ_buff = new int[size_array];
}

// Destructor
CircularBuffer::~CircularBuffer() {
	delete circ_buff;
}

// Method of a inserting value
void CircularBuffer::insert(int value) {
	int income_val = value;

	if (top == size_array) {
		std::cerr << " ::Element was overwritten:: " << std::endl;
		top = 0;
	}

	circ_buff[top] = income_val;
	++top;
}

// Method of the printing circular buffer
void CircularBuffer::print() const {
	std::copy(circ_buff, circ_buff + size_array, std::ostream_iterator<int>(std::cout, " "));
}

// Method return of size array
int CircularBuffer::size() const{
	return size_array;
}