// Header File Vector.h

class Vector { // The class name.
private: // access specifier.
	int x, y; // Data elements.
public: // access specifier.
	int z, w;
	Vector(int, int);
	Vector(int);
	Vector();
	~Vector();

	double counVec(int, int);
	void set(int, int);
	void show();

	Vector operator+ (Vector&);
	Vector& operator= (Vector&);
	Vector operator* (int);
	friend Vector operator* (int, Vector);

	friend Vector operator* (Vector&, Vector&);
};