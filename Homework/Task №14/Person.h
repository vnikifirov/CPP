#pragma once

// Libraries
#include <iostream>
#include <string>
#include <exception>

class Person {
private:
	// Members of class
	std::string firstName,
				lastName;
	int			ID, age;
public:
	// Constructor
	Person();
	// Copy constructor
	Person(const Person&);
	// Constructor with arguments
	Person(const int, const std::string, const std::string, const int);

	// Add methods
	void pushID(const int);
	void pushFirstName(const std::string);
	void pushLastName(const std::string);
	void pushAge(const int);

	// Access methods
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	int getAge() const;

	// The methods of print in console
	void printID() const;
	void printFristName() const;
	void printLastName() const;
	void printAge() const;
	void printHuman() const;

	// Remove info about a person
	void removeID();
	void removeFirstName();
	void removeLastName();
	void removeAge();
};
