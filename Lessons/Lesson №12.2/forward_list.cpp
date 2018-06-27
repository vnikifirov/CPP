#include <iostream>
#include <forward_list>
#include <conio.h>

int main() {
	std::forward_list<int> list = {3,26,12,45,32};
	auto key = list.begin();
	auto list_before = list.before_begin();

	for (; key != list.end(); ++key, ++list_before) {
		if (*key % 2 == 0) {
			break;
		}
	}

	list.insert_after(list_before, 5);

	key = list.begin();
	for (; key != list.end(); ++key) {
		std::cout << *key << std::endl;
	}

	_getch();
}