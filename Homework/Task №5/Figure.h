#pragma once

class Figure {
private:
	int* countArea(int*);
public:
	Figure();
	Figure(int);
	~Figure();

	void pushSide(int);
	void showArea();
	void showSide();

protected:
	int* arrNum;
	int size;
	int top;
};