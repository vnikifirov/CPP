#include <iostream>
#include "Array.h"

Array::Array() {
	// Default values.
	stackPtr = 0;
	size = 0;
}

Array::Array(int s) {
	size = s;
	stackPtr = new int[size];

	for (int i(0); i < size; i++)
		stackPtr[i] = 0;
}

Array::~Array() {
	// Freeing memory for the array.
	delete[] stackPtr;
}

int *Array::addPrt(int *arr, int size, int number) {
	// Distinguish memory for a array.
	if (size == 0)
		arr = new int[size + 1];

	// If the array is no longer empty, copy the data to a temporary array.
	else {																		
		// Create the temporary array.
		int *copy = new int[size + 1];
		// Copy the addresses already defined values.
		for (int i(0); i < size; i++)
			copy[i] = arr[i];
		// Frees memory, which indicates values.
		delete[] arr;

		for (int i(0); i < size; i++)
			// Pointer to show what addresses are now invoked.
			arr[i] = copy[i];													

		delete[] copy;
	}

	// Copy the new number in arr [index] item.
	arr[size] = number;

	return arr;
}
// push() inserts an object at the end of the queue
void Array::push(int number) {
	stackPtr = addPrt(stackPtr, size, number);
	// Increase the size of the array.
	size++;
}

// Pop deletes the first object in the queue.
void Array::pop() {
	while (size > 0)
		std::cout << stackPtr[--size] << std::endl;
}

int &Array::operator[](int index) {
	// Place to call [] will return to the link object itself.
	return stackPtr[index];
}