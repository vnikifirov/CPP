#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector(int X, int Y) { // Construct on two arguments.
	x = X;
	y = Y;

	cout << "constr2 \n";
}

Vector::Vector(int X) {
	x = y = X;
}

Vector::Vector() {
	x = 0;
	y = 0;

	cout << "constr0 \n";
}

Vector::~Vector() {
	cout << "Destr \n";
}
//
//Vector Vector:: operator* (int tmp) {
//Vector obj(this -> x * tmp, this -> y * tmp);
//
//return obj;
//}

Vector Vector::operator+(Vector &tmp) {
	return Vector(this->x + tmp.x, this->y + tmp.y);
}

Vector operator*(int var1, Vector obj1) {
return Vector(var1 * obj1.x, var1 * obj1.y);
}


Vector operator*(Vector &obj1, Vector &obj2) {
	return Vector(obj1.x * obj2.x, obj1.y * obj2.y);
}

Vector& Vector::operator= (Vector& tmp) {
	x = tmp.x;
	y = tmp.y;

	return *this;
}

double Vector::counVec(int x, int y) { // Calculate the length of the vector.
	return sqrt(x * x + y * y);
}

void Vector::set(int X, int Y) {
	this->x = X;
	this->y = Y;

	return;
}

void Vector::show() { // A class method displays results.
					  //	double lenVec = counVec(x, y);
	cout << x << " " << y << endl;

	/*
	cout << "|V|: " << char(251) << "(" << x
	<< "^2" << " + " << y << "^2" << ")" << " = " << lenVec << endl;
	*/
	return;
}