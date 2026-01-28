#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // rand
#include <iostream> // cout

using std::cout;

Base::~Base() {}

Base* generate(void)
{
	int randNum = rand() % 3;
	if (randNum == 0)
		return new A();
	else if (randNum == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (p == NULL)
	{
		cout << "Pointer is NULL\n";
		return;
	}

	cout << "Identifying by adress\n";
	if (dynamic_cast<A*>(p) != NULL)
	{
		cout << "Class is of type A\n";
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		cout << "Class is of type B\n";
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		cout << "Class is of type C\n";
	}
}

void identify(Base& p)
{
	cout << "Identifying by reference\n";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Class is of type A\n"; // output: A
		return ;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Class is of type B\n"; // output: B
		return ;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Class is of type C\n"; // output: C
	}
	catch (...)
	{
	}
}