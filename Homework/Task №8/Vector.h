#pragma once

#include <algorithm>
#include <vector>
#include <cstdlib>
#include "Books.h" // - Books class, iostream and string

template <typename dest>
class Vector
{
public:
	// Default Constructor
	// Overload Constructor
	// ~Destructor

	// Accessor Functions
	void printVector(std::vector<dest>&) const;
		// printVector - print the informatons of all Books
		// @pragma vector<Books>& - books of class
	
	// Mutator Functions
	void fillArr(std::vector<dest>&);
		// fillArr - fill in books information
		// @pragma vector<Books>& - Books in class
	void insertionSort(std::vector<dest>&);
		// insertionSort - sorting of information in object
		// @pragma template <class T> vector<T>& - objBook of class
	void quickSort(std::vector<dest>&, unsigned int, unsigned int);
		// quickSort - sorting of information in object
		// @pragma template <class T> vector<T>&, unsigned int, unsigned int - objBook of class
private:
	// Members Functions
};

template <typename dest>
void Vector<dest>::fillArr(std::vector<dest>& vectorBook)
{
	// Members of function
	std::string titleBook;
	unsigned int rating, amountBooks;

	std::cout << "How many books to you've read? Answer: ";
	std::cin >> amountBooks;

	for (unsigned int i(0); i < amountBooks; ++i)
	{
		std::cout << "Enter title of book #" << i << ": ";
		std::cin.ignore(1, '\n');// - Clears one or more simbols from the input buffer. 
		std::getline(std::cin, titleBook);
		std::cout << "Enter your reating of book (0-10): ";
		std::cin >> rating;

		Books objBook(titleBook, rating);	// Filling to data of array
		vectorBook.push_back(objBook);	// Set of object into vector
	}
	std::cout << std::endl;
}

template <typename dest>
void Vector<dest>::printVector(std::vector<dest>& vectorBook) const
{
	unsigned int size = vectorBook.size(); // Take size of array

	// Dispaly of information about object
	for (unsigned int i(0); i < size; ++i)
	{
		std::cout << "Book name: " << vectorBook[i].getBook() << std::endl;
		std::cout << "Your rating book: " << vectorBook[i].getRatings() << std::endl;
		std::cout << std::endl;
	}
}

template <typename dest>
void Vector<dest>::insertionSort(std::vector<dest>& vectorBook)
{
	// Members of function
	unsigned int size = vectorBook.size(); // Determination size of array
	unsigned int j;
	
	// Insertion sort of array
	for (unsigned int i(1); i < size; ++i)
	{
		j = i;

		// Comparison.Algorithm: index not equal to zero and
		// backward element greater than forward element.
		while ((j > 0) && (vectorBook[j - 1].getRatings() > vectorBook[j].getRatings()))
		{
			// Swaping and decrement of index element
			std::swap(vectorBook[j - 1], vectorBook[j--]); 
		}
	}
}

template <typename dest>
void Vector<dest>::quickSort(std::vector<dest>& vectorBook, unsigned int begin, unsigned int end)
{
	// Members of function
	unsigned int i = begin, j = end;
	// Calculating middle of array
	unsigned int pivot = vectorBook[(i + j) / 2].getRatings();

	// Partition and swaping of elements into array
	while (i <= j)
	{
		// Comparison. Algorithm: lessIndex < pivot < greaterIndex (Would be an error - lessIndex <= pivot)
		while (vectorBook[i].getRatings() < pivot) // This's left half
			++i;	
		while (vectorBook[j].getRatings() > pivot) // This's right half
			--j;
		// Swap to greate element of lesser element
		if (i <= j) 
			std::swap(vectorBook[i++], vectorBook[j--]);
	}
	// Recursive call of function
	if (j > begin)
		quickSort(vectorBook, begin, j);
	if (i < end)
		quickSort(vectorBook, i, end);
}