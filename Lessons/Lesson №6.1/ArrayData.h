#pragma once

class ArrayData {
protected:
	int *stackPtr;
	int size;
	int top;
	int lenght;
public:
	ArrayData();
	ArrayData(int);
	~ArrayData();

	void push(int);
	void print();
	int showArr();
};