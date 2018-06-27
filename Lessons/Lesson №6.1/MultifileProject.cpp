#include <iostream> // every program has this.
#include <cstdlib> // standart library.
#include <ctime> // For math rand.

#include "Man.h"
#include "Student.h"
#include "AbsentiaStudent.h"
#include "Teacher.h"

using namespace std;

int main() {
	Teacher Igor("Igor", "Seliverstov", 4320.0, 4.07);
	Student Vasy("Vasy", "Ivanov", true, 10);
	AbsentiaStudent Pety("Pety", "Vasylev", true, 10, 10000);

	long seed = time(NULL);
	srand(seed);

	for (int i(0); i < 10; i++) {
		Vasy.push(2 + rand() % 4, i);
		Pety.push(2 + rand() % 4, i);
	}

	cout << "First teacher" << endl;
	Igor.getFullName();
	Igor.showMoney();
	cout << "Log" << endl;
	Igor.push(Vasy, 0);
	Igor.push(Pety, 1);
	Igor.getAllStudents();
	cout << endl;

	cout << "First student" << endl;
	Vasy.getFullName();
	Vasy.showAverageScore();
	Vasy.showAccessSession();
	cout << endl;

	cout << "Second student" << endl;
	Pety.getFullName();
	Pety.showAverageScore();
	Pety.showAccessSession();
	cout << endl;

	system("pause");
	return 0;
}