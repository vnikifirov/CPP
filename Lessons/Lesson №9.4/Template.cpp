#include <iostream>
#include <conio.h>

/*						Homework
	First: necessary to look syntax at the template class.
	Second: create a template class array.
		Constructor class.
		~Destructor class.
		With two methods.
			sorting by "insertion" type.
			sorting by "tim sort" type.

	Wednesday 17:30.
*/

template<class T>
T mod(T n) {
	return (n < 0) ? -n : n;
}

template<class T>
void sortyArr(T* arr, int lenght) {
	T swap;
	for(int i(0); i < (lenght - 1); i++)
		for (int j(0); j < (lenght - i); j++) {
			if (arr[j] > arr[j+1]) {
				swap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = swap;
			}
		}
}

int main() {
//	std::cout << mod(-10) << std::endl;
//	std::cout << mod(-10.45) << std::endl;

	int arrOne[] {5, 23, 8, 6};
	double arrTwo[] { 5.5, 23.4, 8.12, 3.14};

	sortyArr(arrOne, 3);
	sortyArr(arrTwo, 3);

	for (auto i : arrOne)
		std::cout << i << std::endl;

	for (auto i : arrTwo)
		std::cout << i << std::endl;

	_getch();
}