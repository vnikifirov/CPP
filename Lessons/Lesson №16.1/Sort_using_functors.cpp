#include <iostream>
#include <conio.h>
#include <string>
#include <set>
#include <functional>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

class Human {
public:
	Human() = default;
	
	Human(string firstName, string lastName) {
		this->firstName = firstName;
		this->lastName = lastName;
	}

	string getFirstName() const {
		return firstName;
	}

	string getLastName() const {
		return lastName;
	}

private:
	string firstName,
		   lastName;
};

// Template of Predicate #1
template<typename T>
class Createry1 {
public:
	bool operator()(const T& obj1, const T& obj2) const {
		return obj1.getLastName() < obj2.getLastName()
			|| (obj1.getLastName() == obj2.getLastName()
				&& obj1.getFirstName() < obj2.getFirstName());
	}
};

// Tempalte of Predicate #2
template <typename T>
class Createry2 {
public:
	bool operator()(const T& obj1, const T& obj2) const {
		return obj1.getLastName() > obj2.getLastName()
			|| (obj1.getLastName() == obj2.getLastName()
				&& obj1.getFirstName() > obj2.getFirstName());
	}
};

// Functors
class Sequance {
private:
	// Record condition
	int condition;
public:
	// Constructor
	Sequance(int incomeValue) : condition(incomeValue) {}

	// Overlow of operator parenthesis
	int operator()() {
		return condition++;
	}
};

template<typename T>
bool sorty(T, T);

int main() {
	set<Human, Createry1<Human>> people1;
	set<Human, Createry2<Human>> people2;
	set<Human, Createry2<Human>> people3;

	set<int, less<int>> values1;
	set<int, greater<int>> values2;

	list<int> myFunctor;

	generate_n(back_inserter(myFunctor), 10, Sequance(1));
	copy(myFunctor.cbegin(), myFunctor.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;

	generate(next(myFunctor.begin()), prev(myFunctor.end()), Sequance(100));
	copy(myFunctor.cbegin(), myFunctor.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;

//	for_each();
	transform(myFunctor.begin(), myFunctor.end(), myFunctor.begin(),
		[=](int value) mutable -> int {
			return value * value;
		}
	);

	people1.insert({
		Human("Vasy", "Pupkin"), 
		Human("Ivan", "Shishkyn"),
		Human("Pety", "Ivanov"),
		Human("Artur", "Shishkyn"),
		Human("Misha", "Sidorv")
	});

	people2.insert({
		Human("Vasy", "Pupkin"),
		Human("Ivan", "Shishkyn"),
		Human("Pety", "Ivanov"),
		Human("Artur", "Shishkyn"),
		Human("Misha", "Sidorv")
	});

	people3 = people2;

	for (auto key : people3) {
		cout << key.getFirstName() << " "
			<< key.getLastName() << endl;
	}

	values1.insert({ 1, 2 ,3 , 4, 5 });
	values2.insert({ 1, 2 ,3 , 4, 5 });

//	values1 = values2;

	_getch();
}

template<typename T>
bool sorty(T x, T y) {
	return x < y;
}