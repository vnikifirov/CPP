// calc-len-vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// input/ output / namespace.
#include <iostream>	
// Vector class.
#include "Vector.h"

using namespace std; // The space name the std.

// Prototype function.
int randValue(int); 

int main() {
	// Variable with rand number.
	int 
		coordinateX,
		coordinateY;
	// Declaration of the object and send two argument.
	Vector lentVec(10, 8);

	cout << "Enter the coordinates of the x = ";	
	cin >> coordinateX;
	cout << "Enter the coordinates of the y = ";	
	cin >> coordinateY;
	
	// Clears the screen.
	system("pause"); // Clears the screen.
	system("CLS");

	lentVec.set(coordinateX, coordinateY); // Class function call. Initialization of variables.
	lentVec.show(); // Class function call. Show results.

	std::cout << "Press any key to continue..." << std::endl;
	system("pause");
	system("CLS"); // Clears the screen.
	
	Vector a1(1, 2), b1(2, 5), c1;
	c1 = a1 + b1;
	c1.show();

	std::cout << "Press any key to continue..." << std::endl;
	system("pause");
	system("CLS");

	Vector a2(5, 3), c2;
	c2 = a2 * 2;
	c2.show();	

	std::cout << "Press any key to continue..." << std::endl;
	system("pause"); // Clears the screen.
	system("CLS");

	Vector a3(5, 6), b2;
	b2 = a3;
	b2.show();

	system("pause");
	return 0;
}

// Radom numbers generator
int randValue(int randNum) {
	// Generation of the random number.
	if (rand() % 2)
		randNum = rand() % 100;
	else
		randNum = rand() % 100 * (-1);

	return randNum;
}