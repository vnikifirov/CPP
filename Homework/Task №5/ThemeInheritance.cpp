#include <iostream>

#include "Square.h"
#include "Parallelogram.h"
#include "Triangle.h"

int main() {
	Square sArea(2);
	Parallelogram pArea(2);
	Triangle tArea(2);

	std::cout << "Object Square" << std::endl;
	sArea.pushSide(10);
	sArea.pushSide(10);
	sArea.showSide();
	sArea.showArea();

	std::cout << "Object Parallelogram" << std::endl;
	pArea.pushSide(12);
	pArea.pushSide(5);
	pArea.showSide();
	pArea.showArea();

	std::cout << "Object Triangle" << std::endl;
	tArea.pushSide(6);
	tArea.pushSide(9);
	tArea.showSide();
	tArea.showArea();

	system("pause");
	return 0;
}