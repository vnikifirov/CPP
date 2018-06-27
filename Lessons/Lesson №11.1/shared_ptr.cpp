#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <conio.h>

int main()
{
	std::shared_ptr<std::string> strPtr(new std::string("pety"));
	std::shared_ptr<std::string> strPtrTwo = std::make_shared<std::string>("vasy");
	std::vector<std::shared_ptr<std::string>> my_vector;

	(*strPtr)[0] = 'P';

	strPtrTwo->replace(0, 1, "V");

	my_vector.push_back(strPtr);
	my_vector.push_back(strPtrTwo);
	my_vector.push_back(strPtr);
	my_vector.push_back(strPtrTwo);
	my_vector.push_back(strPtrTwo);

	for (auto i : my_vector)
		std::cout << *i << std::endl;
	std::cout << std::endl;

	*strPtr = "Olga";

	for (auto i : my_vector)
		std::cout << *i << std::endl;
	std::cout << std::endl;

	std::cout << my_vector[0].use_count() << std::endl;

	my_vector[2] = strPtrTwo;

	std::cout << my_vector[0].use_count() << std::endl;

	strPtr = strPtrTwo;

	std::cout << my_vector[0].use_count() << std::endl;

	std::cout << my_vector[0].unique() << std::endl;

	std::cout << my_vector[0].get() << std::endl;
	std::cout << my_vector[1].get() << std::endl;
	std::cout << my_vector[2].get() << std::endl;

	_getch();
}