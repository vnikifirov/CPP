#include <iostream>
#include <utility>
#include <conio.h>
#include <tuple>
#include <string>

int main()
{
	auto my_pr = std::make_pair(42, "some what");
	int i = 0;
	auto second_pr = std::make_pair(std::ref(i), std::ref(i));

	second_pr.first += 10;
	++second_pr.second;
	
	std::cout << i << std::endl;

	std::tuple<int, int, char> my_tuple(1,50,'D');
	std::tuple<int, int, char> my_tupleTwo(5, 0, 'C');

	std::cout << std::get<0>(my_tuple) << std::endl;
	std::get<1>(my_tuple) = std::get<2>(my_tupleTwo);
	std::cout << std::get<0>(my_tuple) << std::endl;

	std::string my_string;
	std::tuple<std::string&> my_tupleThree(my_string);

	std::get<0>(my_tupleThree) = "Some string";
	std::cout << my_string << std::endl;	
	my_tuple.swap(my_tupleTwo);
	
	int j;
	int l;
	char my_char;
//	std::make_tuple(std::ref(j), std::ref(l), std::ref(my_char)) = my_tuple;
	std::tie(j, l, std::ignore) = my_tuple;

	_getch();
}