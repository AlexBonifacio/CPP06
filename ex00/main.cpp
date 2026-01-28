
#include <iostream>
#include "ScalarConverter.hpp"


int main(int argc, char **av)
{
	(void)argc;
	(void)av;
	ScalarConverter::convert(av[1]);
	return 0;
}