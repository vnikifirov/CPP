#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
	int n = 100;
	double pi = 3.14;

/*
	cout.unsetf(ios::dec);
	cout.setf(ios::oct);
//	cout.setf(ios::);
	cout.width(50);
	cout.unsetf(ios::right);
	cout.setf(ios::left);
	cout.fill('*');
*/
	cout << oct << n << endl;
	cout << dec << n << endl;
	cout << setw(100) << setfill('/') << n << endl;	
	cout << setprecision(20) << pi << endl;

	cout.setf(ios::hex, ios::basefield);
	cout << n << endl;

	_getch();
}