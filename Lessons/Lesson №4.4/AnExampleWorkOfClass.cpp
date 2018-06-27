#include <iostream>

using namespace std;

class Vector {
private:
	int x1, y1, x2, y2;

public:

	Vector() {
		x1 = y2 = x2 = y1 = 0;
	}

	Vector(int a, int b, int c, int d) {
		x1 = a;
		x2 = b;
		y1 = c;
		y2 = d;
	}

	void set(int a, int b, int c, int d) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}

	void show() {
		cout << x1 << " " << y1 << " " << x2 << " " << y2;
	}
};

int main() {
	Vector a, b(1, 2, 3, 4);

	a.set(4, 5, 3, 10);
	b.set(3, 1, 4, 2);

	a.show();
	b.show();

	system("pause");
	return 0;
}