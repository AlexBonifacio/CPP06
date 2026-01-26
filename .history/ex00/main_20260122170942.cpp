
#include <iostream>
#include "ScalarConverter.hpp"


int main(int argc, char **av)
{
	(void)argc;
	float a = 2f;
	std::cout << a + 1.1 << '\n';
	ScalarConverter::convert(av[1]);
	return 0;
}