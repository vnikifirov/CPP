#include <iostream>
#include <conio.h>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>

using namespace std;

// Comparing numbers
bool compare(int, int);

int main() {
	set<int, std::greater<int>> things;
	vector<int> vec = {5,2,3,4,0};
	int arr[]{3,5,7,9,1};

	things.insert({1,2,0,4,5});
	things.insert(3);

	for (auto i : things) {
		cout << i << endl;
	}

	auto key = vec.begin();
	for (; key != vec.end(); ++key) {
		if (*key % 2 == 0) {
			break;
		}
	}
	vec.push_back(6);

	copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(cbegin(arr), cend(arr), ostream_iterator<int>(std::cout, " "));

	sort(arr, arr + 5, compare);
	cout << std::endl;
	copy(arr, arr + 5, ostream_iterator<int>(cout, " "));

	_getch();
}

// Comparing numbers
bool compare(int x, int y) {
	return (x > y);
}