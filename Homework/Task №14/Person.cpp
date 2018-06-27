#include "Person.h"

// Constructor
Person::Person() = default;
// Constructor with arguments
Person::Person(const int _ID, const std::string _firstName,
	const std::string _lastName, const int _age) : 
	ID(_ID), firstName(_firstName), lastName(_lastName),
	age(_age) {}
// Copy constructor
Person::Person(const Person& obj) :
	ID(obj.ID),
	firstName(obj.firstName), 
	lastName(obj.lastName),
	age(obj.age) {}

// Define of ID
void Person::pushID(const int ID) {
	this->ID = ID;
}
// Define of FirstName
void Person::pushFirstName(const std::string firstName) { 
	this->firstName = firstName;
}
// Define of LastName
void Person::pushLastName(const std::string lastName) {
	this->lastName = lastName;
}
// Define of Age
void Person::pushAge(const int age) {
	this->age = age;
}

// Recess of ID
int Person::getID() const {
	if (ID <= 0) {
		throw std::runtime_error("ID is empty!");
	}
	else { return ID; }
}
// Recess of FirsName
std::string Person::getFirstName() const {
	if (!firstName.size()) {
		throw std::runtime_error("firstName is empty!");
	} else { return firstName; }
}
// Recess of lastName
std::string Person::getLastName() const {
	if (!lastName.size()) {
		throw std::runtime_error("lastName is empty!");
    } else { return lastName; }
}
// Recess of Age
int Person::getAge() const {
	if (age <= 0) {
		throw std::runtime_error("age is empty!");
	} else { return age; }
}

// Display of ID
void Person::printID() const {
	if (ID <= 0) { getID(); }
	else { std::cout << ID << " "; }
}
// Display of FirstName
void Person::printFristName() const {
	if (!firstName.size()) { getFirstName(); }
	else { std::cout << firstName << " "; }
}
// Display of lastName
void Person::printLastName() const {
	if (!lastName.size()) { getLastName(); }
	else { std::cout << lastName << " "; }
}
// Display of Age
void Person::printAge() const {
	if (age <= 0) { getAge(); }
	else { std::cout << age << " "; }
}
// Display of all info about individual
void Person::printHuman() const {
	printID();
	printFristName();
	printLastName();
	printAge();
}

// Remove of ID
void Person::removeID() {
	if (ID <= 0) { getID(); }
	else { ID = 0; }
}
// Remove of FristName
void Person::removeFirstName() {
	if (!firstName.size()) { getFirstName(); }
	else { firstName = ""; }
}
// Remove of LastName
void Person::removeLastName() {
	if (!lastName.size()) { getLastName(); } 
	else lastName = "";
}
// Remove of Age
void Person::removeAge() {
	if (age <= 0) { age = -1; } 
	else { getAge(); }
}