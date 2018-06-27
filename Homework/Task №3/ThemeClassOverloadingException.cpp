// TASK
// How to create a stack use pointers 
// 1) First create a class.
// 2) Secondly, the class must match the size of the array
// 3) it was not a negative.
// 4) Operator overloading "brackets".
// 5) Return link.

#include <iostream>
#include "Array.h"

using namespace std;

int main() {
	Array firstObj(10);

	for (int i(1); i < 10; i++)
		firstObj[i] = i + 1;
	firstObj.pop();

	system("pause");
	return 0;
}