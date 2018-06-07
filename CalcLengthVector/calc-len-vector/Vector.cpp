#include "Vector.h"
#include "stdafx.h"

#include <iostream>

// Construct with two arguments.
Vector::Vector(int X, int Y) {
	x = X;
	y = Y;

	std::cout << "CALL CONSTRUCTOR-2\n";
}

// Constrtuctor with one arg
Vector::Vector(int X) {
	x = y = X;
}

// Constrtuctor
Vector::Vector() {
	x = 0;
	y = 0;

	std::cout << "CALL - CONSTRUCTOR-1\n";
}

// Destrtuctor
Vector::~Vector() {
	std::cout << "CALL - DESTRUCTOR \n";
}

// Overload sum of two vectors
Vector Vector::operator + (const Vector &other) {
	return Vector(this->x + other.x, this->y + other.y);
}

// Trivial copy assignment operator
Vector& Vector::operator = (const Vector& other) {
	x = other.x;
	y = other.y;

	return *this;
}

// Overload x = r × cos( θ ) / y = r × sin( θ )
Vector Vector:: operator* (int angle) {
	Vector obj(this->x * angle, this->y * angle);

	return obj;
}

// Overload x = r × cos( θ ) / y = r × sin( θ )
Vector operator*(const Vector& other, int angle) {
	return Vector(angle * other.x, angle * other.y);
}
 
// Overload Vector Product a × b
Vector Vector::operator * (const Vector &other) {
	return Vector(this->x * other.x, this -> y * other.y);
}

// Calculate the Magnitude of the vector.
double Vector::getMagnitude(int x, int y) {
	return sqrt(x * x + y * y);
}

// Setter Function
void Vector::set(int X, int Y) {
	this->x = X;
	this->y = Y;

	return;
}

void Vector::show() { // A class method displays results.
					  //	double lenVec = counVec(x, y);
	std::cout << this->x << " " << this->y << std::endl;
	return;
}