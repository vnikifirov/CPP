#include <iostream>
#include <utility>
#include <conio.h>

int main()
{
	auto my_pr = std::make_pair(42, "some what");
	int i = 0;
	auto second_pr = std::make_pair(std::ref(i), std::ref(i));

	++second_pr.first;
	++second_pr.second;

	std::cout << i << std::endl;

	getch();
}

