/*//////////////////Tasks/////////////////////////
Main tasks					//
1) Calculate the length of the vector.			//
2) Keyboard Input data.						//
3) Construct on two arguments.					//
Additional tasks				//
1) Vector turn on a certain number of degrees.	//
2) Use the addition operator overload			//
*/////////////////////////////////////////////////

#include <iostream>	// input/ output / namespace.
#include "Vector.h" // Connect class Vector.

using namespace std; // The space name the std.

int randValue(int); // Prototype function.

int main() {
	/*int coordinateX, // Variable with rand number.
	coordinateY;
	Vector lentVec(10, 8); // Declaration of the object and send two argument.

	cout << "Enter the coordinates of the x = ";	cin >> coordinateX;
	cout << "Enter the coordinates of the y = ";	cin >> coordinateY;
	system("CLS"); // Clears the screen.

	lentVec.set(coordinateX, coordinateY); // Class function call. Initialization of variables.
	lentVec.show(); // Class function call. Show results.
	*/

	/*
	Vector a(1, 2), b(2, 5), c;
	c = a + b;
	c.show();
	*/
	
	Vector a(5, 3), b, c;
	c = a * 2;
	b = 2 * a;
	c.show();
	b.show();
	
	Vector a(5, 6), b;
	b = a;
	b.show();

	system("pause");
	return 0;
}

int randValue(int randNum) {
	// Generation of the random number.
	if (rand() % 2)
		randNum = rand() % 100;
	else
		randNum = rand() % 100 * (-1);

	return randNum;
}