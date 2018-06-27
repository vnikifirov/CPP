#include "Queue.h"

// Default constructor for five elements
Queue::Queue() :
	size_array(5), front(-1),
	rear(-1), circle(false) {
	circ_buff = new int[size_array];
}

// Overfull constructor
Queue::Queue(int size) :
	size_array(size), front(-1),
	rear(-1), circle(false) {
	circ_buff = new int[size_array];
}

// Destructor
Queue::~Queue() {
	delete circ_buff;
}

// Cheak to queue is empty or not
bool Queue::is_empty() const {
	if ((front == -1) && (rear == -1)) {
		return true;
	} else {
		return false;
	}
}

// Method of a inserting value
void Queue::push_back(int value) {
	int income_val = value;

	if (front == -1 && rear == -1) {
		// Begin of write
		front = 0;
	} else {
		if (rear == (size_array - 1)) {
			// After did a circle
			rear = -1;
			circle = true;
		} else {
			// It'll overwrite of an element
			if ((front == (size_array - 1)) && circle) {
				front = 0;
				circle = false;
			}
		}
	}
	// Insert of element
	circ_buff[++rear] = income_val;

	// Shift of pointer at frist element
	if (circle)
		++front;
}

// Method remove of frist added element
std::vector<int> Queue::pop_front() {
	std::vector<int> tmp;
	// Definition of size vector with elements
	tmp.resize(2);

	// If this's empty
	if ((front == -1) && (rear == -1)) {
		std::cerr << "::Your list is empty::" << std::endl;
		tmp[0] = tmp[1] = -1;
		return tmp;
	} else {
		if (front == rear) { // If all elements was removed
			tmp[0] = circ_buff[front];
			tmp[1] = 1;
			front = rear = -1;
			return tmp;
		} else if ((front == size_array) && circle) { // If elements was overwritten
			front = 0;
			circle = false;
		}
	}

	// Delete of element
	tmp[0] = circ_buff[front++];
	tmp[1] = 1;
	return tmp;

	// (front == (size_array - 1)) && !circle
}

// Method of the printing circular buffer
void Queue::print() const {
	if ((front == -1) && (rear == -1)) {
		return; // Exit
	} else {
		int index = front;
		bool copy_circle = circle;

		while (index < size_array) { // There is small of error here!
			// Print of one element from circ_buff
			std::cout << circ_buff[index++] << ' ';
			
			// If elements was overwritten 
			if ((index == size_array) && copy_circle) {
				index = 0;
				copy_circle = false;
			}

			// If come up to front and break of loop
			if ((index == front) && !copy_circle || rear == front)
				break; // Exit
		}
	}
}

// Method return of front value
int Queue::peek() const {
	if ((front != -1) && (rear != -1))
		return circ_buff[front];
}

// Method return of last value
int Queue::back() const {
	if ((front != -1) && (rear != -1))
		return circ_buff[rear];
}

// Method return of totally size array
int Queue::size() const {
	return size_array;
}
