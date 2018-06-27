#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

class CompareStr {
	bool operator()(const std::string& str_1,
		const std::string& str_2) const {
		return str_1.length() > str_2.length();
	}
};

template<typename T> 
class Multiplay {
public:
	T operator()(const T& num_1, const T& num_2) {
		return num_1 * num_2;
	}
};

class Times {
public:
	bool operator()(int num) {
		return (num % 2) == 0;
	}
};

template<typename T>
class Greater {
public:
	bool operator()(T value_1, T value_2) {
		return value_1 > value_2;
	}
};

int subtraction(int, int);

int main() {
	int arr[] = {4,2,5,1,3};
	int sub_1 = accumulate(begin(arr), end(arr), 1, subtraction);

	cout << accumulate(begin(arr), end(arr), 0) << endl;
	cout << accumulate(begin(arr), end(arr), 1, Multiplay<int>()) << endl;
	cout << sub_1 << endl;
	cout << count_if(begin(arr), end(arr), Times());
	sort(begin(arr), end(arr), Greater<int>());
	cout << endl;

	for (auto key : arr) {
		cout << key << endl;
	}

	cout << count_if(arr, arr + 5, [](const int value) { return (value % 5) == 0; });

	_getch();
}

int subtraction(int sub, int num) {
	return sub -= num;
}