// pointers-and-strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Edited [5-01-2018] by Vadim N.
// COUTION: Having an issue at separatorString function
// NOTE: The problem was solved

#define _CRT_SECURE_NO_WARNINGS

// Vendors libs
#include <boost/algorithm/string.hpp>
#include <boost/assign/std/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

// Prototype of the function.
#include <iostream>
// For work with string.
#include <cstring>
// Obj string.
#include <string>
//#include <algorithm>

using namespace boost::numeric::ublas;

const char COMMA = ',';
const char DOT = '.';

// Prototype of the functions.
void PrintContent(std::vector<std::string> vec);

int main() {
	std::string userInput;
	std::vector<std::string> results;

	std::cout << "Enter your text : ";
	// Dereferencing pointer and get value in string.
	std::getline(std::cin, userInput);
	// Cleaning the screen.
	system("CLS");
	
	size_t delimiters = 0;
	// implicitly captures the variable "delimiters" by reference
	std::for_each(userInput.begin(), userInput.end(), [&delimiters](char c) -> void {
		if (c == ',' || c == '.') 
		{
			// increment...
			++delimiters;
		}
	});
	
	// lambda exprestion/Split txt.
	boost::split(results, userInput, [](char c) -> bool { return (c == ',' || c == '.'); });

	// Sorting words.
	std::sort(results.begin(), results.end(), [](std::string x, std::string y) -> bool { return x < y; });

	std::cout << "Source string : " << userInput << std::endl;
	std::cout << "Delimiters in the string: " << delimiters << std::endl;
	std::cout << "Result: " << std::endl;
	PrintContent(results);

	std::cin.get();
	return 0;
}

void PrintContent(std::vector<std::string> vec)
{
	// Print the content of row by row on screen
	for (std::string data : vec)
	{
		std::cout << data << std::endl;;
	}
}