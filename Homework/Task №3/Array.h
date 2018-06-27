#pragma once

class Array {
private:
	int *stackPtr, size;				// Data elements.

	int* addPrt(int*, int, int);		// Encapsulated method.

										//	friend void setInArr(int, Array&);	// Declare friendly features.
										//	friend void getFromArr(Array&);		// ...
public:
	Array();							// Constructor the class.
	Array(int);							// ...
	~Array();							// Destructor the class.

	void push(int);						// Declare the class methods.
	void pop();							// ...

	int &operator[](int);				// Overload [].
};