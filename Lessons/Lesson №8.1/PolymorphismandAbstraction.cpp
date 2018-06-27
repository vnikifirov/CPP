#include "Class.h"

int main() {
	Man* ptr [100];	
	int number = 0;
	char choose;
	
	do {
		cout << "s or t: ";
		cin >> choose;

		if (choose == 's')
			ptr[number] = new Student; // Free momory.
		if (choose == 't')
			ptr[number] = new Teacher; // Free momory.
		ptr[number++]->put();
		
		cout << "y or n: ";
		cin >> choose;
	} while (choose == 'y');
	
	for (int i(0); i < number; i++) {
		ptr[i]->getName();

		if (ptr[i]->goodMan())
			cout << "This man is good" << endl;
	}



	system("pause");
	return 0;
}