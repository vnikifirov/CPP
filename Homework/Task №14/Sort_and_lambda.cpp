/*//////////////////Tasks///////////////////////////
  Execute sorty by using of lambda-expression and //
  any containers from vector or list              //
*//////////////////////////////////////////////////

// Standart libraries
#include <iostream>
#include <conio.h>

// Sequence container
#include <vector>

// Include library for read of file
#include <fstream>

// Generic Algorithms
#include <algorithm>
#include <iterator>

// Include somewhat
#include <functional>

// Include class - Person
#include "Person.h"

// Using name space
using namespace std;

// Contraction for vector 
typedef vector<Person> vecP;

// Read off of an object
bool read_file(vecP&, string);

// Print out of an object
template <class  iter, class func>
void print(iter, iter, func);

// Start execute of program
int main() {
	try {
		vecP people;
		string nameFile = "listpeople.txt";

		// Read off of an object
		if (!read_file(people, nameFile)) {
			throw runtime_error("unable to open file");
			return (-1);
		}

		// Print out the sorted on fist name of container
		sort(people.begin(), people.end(),
			[](const Person& x, const Person& y) -> bool {
				return x.getFirstName() < y.getFirstName();
			});

		// Print out of an object
		print(people.begin(), people.end(),
			[](const Person& ind) -> string {
				return ind.getFirstName();
			});
	} catch (runtime_error err) {
		cout << "|Error| " << err.what() << endl;
	}

	_getch();
}
   
// Print out of an object
template <class  iter, class func>
void print(iter first, iter last, func f) {
	for (; first != last; ++first) {
		cout << f(*first) << endl;
	}
}

// Read off of an object
bool read_file(vecP& vec, string nameFile) {
	// File open
	fstream file(nameFile, ios::in);
	// Check, file is open
	if (!file.is_open()) { return false; }
	// Read the file...
	while (!file.eof()) {
		string fname, lname; 
		unsigned int ID, age;

		file >> ID >> fname >> lname >> age; // Why doesn't it work? Already it's working!
		Person ind(ID, fname, lname, age); // The object is filling...
		vec.push_back(ind);
	}
	// if file was readed
	return true;
}
