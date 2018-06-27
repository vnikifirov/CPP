#include <conio.h>
#include <iomanip>

#include "Queue.h";

using namespace std;

// Add of element in queue and overwriting of three elements
void add(Queue&, int);
// Remove of elements and at look at them
void remove(Queue&, int);
// Print of elements in queue
void show(Queue&);

int main() {
	const int SIZE = 3; // Amount of elements in queue

	Queue myQ(SIZE);
	int amountAddElements = 3;
	int amountRemoveElements = 2;

	add(myQ, amountAddElements);
	show(myQ);
	remove(myQ, amountRemoveElements);
	show(myQ);

	_getch();
}

void add(Queue& myQ, int amount) {
	for (auto i(0); i < amount; ++i) {
		myQ.push_back(i - 2);
	}
}

void remove(Queue& myQ, int amount) {
	int* items = new int[amount];
	vector<int> tmp;
	tmp.resize(2);

	cout << left << setw(10) << "Elements"
		<< right << setw(10) << "Index"
		<< endl;

	for (auto i(0); i < amount; ++i) {
		tmp = myQ.pop_front();

		if (tmp[1] == -1) {
			break;
		} else {
			items[i] = tmp[0];
			cout << left << setw(10) << items[i]
				<< right << setw(10) << (i + 1)
				<< endl;
		}
	}

	delete items;
}

void show(Queue& myQ) {

	// If the queue is empty
	if (myQ.is_empty()) {
		cout << "::Your queue is empty::" << endl;
		return;
	}

	// Print of elements in queue
	cout << left << setw(10) << "List: ";
	myQ.print();
	cout << endl;
}
