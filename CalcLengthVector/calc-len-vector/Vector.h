#pragma once

class Vector {
private:	
	int x, y;
public:
	int z, w;
	Vector(int, int);
	Vector(int);
	Vector();
	~Vector();

	double getMagnitude(int, int);
	void set(int, int);
	void show();

	Vector operator + (const Vector&);
	Vector& operator= (const Vector&);

	Vector operator * (int);
	Vector operator * (const Vector&);
	friend Vector operator* (const Vector&, int);
};