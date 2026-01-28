
#include "Base.hpp"
#include <cstdlib> // rand
#include <ctime>   // time
#include <iostream> // cout

int main(void)
{
	srand(time(NULL));
	Base *basePtr = generate();

	identify(basePtr);
	std::cout << "-------------------\n";
	identify(*basePtr);

	delete basePtr;
	return 0;
}