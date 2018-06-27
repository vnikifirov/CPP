#include <conio.h>
#include "Vector.h"
#include "Books.h"

int main()
{	
	// Members of program
	std::vector<Books> vectorBook;
	Vector<Books> actionArr;
	// Members algorithm of type QuickSort 
	unsigned int beginArr, endArr;

	// Create of array and filling it
	actionArr.fillArr(vectorBook);
	system("CLS"); // Clear screen
	
	// Print condition before sorting
	std::cout << "Before sorting" << std::endl;
	actionArr.printVector(vectorBook);
/*
	// Sorting with use to insertionSort algorithm
	std::cout << "After sorting - insertionSort" << std::endl;
	actionArr.insertionSort(vectorBook);
	actionArr.printVector(vectorBook);
*/
	// Sorting with use to QuickSort algorithm
	// Determinant of members algorithm
	beginArr = 0, endArr = vectorBook.size() - 1;
	std::cout << "After sorting - QuickSort" << std::endl;
	actionArr.quickSort(vectorBook, beginArr, endArr);
	actionArr.printVector(vectorBook);

	_getch();
}