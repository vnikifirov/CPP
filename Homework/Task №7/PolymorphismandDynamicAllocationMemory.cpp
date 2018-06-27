#include "Man.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

void choise(Man**, int&, char);
void displayRes(Man**, int&);

int main() {
	Man* ptr[100];
	int num{};
	char select{};

	choise(ptr, num, select);
	displayRes(ptr, num);

	for (int i(0); i < num; i++)
		delete ptr[i];

	system("pause");
	return 0;
}

void choise(Man** ptr, int& num, char select) {
	do {
		cout << "s or t: ";
		cin >> select;

		if (select == 's' || select == 'S')
			ptr[num] = new Student;
		if (select == 't' || select == 'T')
			ptr[num] = new Teacher;

		ptr[num++]->put();

		cout << "y or n: ";
		cin >> select;
	} while (select == 'y' || select == 'Y');

	system("CLS");
	return;
}

void displayRes(Man** ptr, int& num) {
	cout << "---Resalt---\n";

	for (int i(0); i < num; i++) {
		ptr[i]->getName();

		if (ptr[i]->goodMan())
			cout << "This person is good" << endl;
		else
			cout << "This person isn't good" << endl;
	}
	return;
}