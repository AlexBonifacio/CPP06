
#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>

using std::cout;

bool ScalarConverter::isPseudoLiteral(const std::string& input)
{
	const std::string pLiterals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	int i = 0;
	while(i < 6 && pLiterals[i] != input)
		i++;

	if (i == 6)
	{
		cout << "Input is not pseudo litteral\n";
		return false;
	}

	cout << "Input is pseudo litteral\n";
	return true;
}

bool ScalarConverter::displayPseudoLiteral(const std::string& input)
{
	if (isPseudoLiteral(input))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";

		if (input == "+inf" || input == "+inff")
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}
		else if (input == "-inf" || input == "-inff")
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}
		else
		{
			std::cout << "float: nanf\n";
			std::cout << "double: nan\n";
		}
		return true;
	}

	return false;
}
/*
	42.0f
	has a dot
	has a f at the end
	has a number after the dot
	can have + or -
*/

bool ScalarConverter::hasExactlyOneDot(const std::string& input)
{
	size_t i = 0;
	bool has_dot = false;

	while (i < input.length())
	{
		if (input[i] == '.')
		{
			if (has_dot == true)
			{
				return false;
			}
			has_dot = true;
		}
		i++;
	}
	return has_dot;
}

bool ScalarConverter::isChar(const std::string& input)
{
	if (input.empty())
		return false;
	
	if (input.length() != 1)
		return false;

	if (!std::isprint(static_cast<unsigned char>(input[0])))
	{
		return false;
	}

	if (std::isdigit(static_cast<unsigned char>(input[0])))
	{
		return false;
	}
	return true;

}

bool ScalarConverter::isFloat(const std::string& input)
{
	size_t i = 0;
	bool has_digit = false;

	if (input.empty())
		return false;

	if (input[i] == '+' || input[i] == '-')
		i++;

	if (!hasExactlyOneDot(input))
	{
		return false;
	}
	

	while (i < input.length())
	{
		if (input[i] == 'f' && i == input.length() - 1)
			return (has_digit);
		if (std::isdigit(static_cast<unsigned char>(input[i])))
		{
			has_digit = true;
		}
		else if (input[i] == '.')
		{
			i++;
			continue;
		}
		else
		{
			return false;
		}
		i++;
	}

	return false;
}

bool ScalarConverter::isDouble(const std::string& input)
{
	size_t i = 0;
	bool has_digit = false;

	if (input.empty())
		return false;
	
	if (input[i] == '+' || input[i] == '-')
		i++;

	if (!hasExactlyOneDot(input))
		return false;
	
	while (i < input.length())
	{
		if (std::isdigit(static_cast<unsigned char>(input[i])))
		{
			has_digit = true;
		}
		else if (input[i] == '.')
		{
			i++;
			continue;
		}
		else
		{
			return false;
		}
		i++;
	}
	if (i == input.length() && has_digit)
	{
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(const std::string& input)
{
	size_t i = 0;

	if (input.empty())
		return false;

	if (input[i] == '+' || input[i] == '-')
		i++;

	if (i == input.length())
		return false;
	
	while (i < input.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
		i++;
	}

	return true;
}

void ScalarConverter::convert(const std::string& input)
{

	Type type;
	if (input.empty())
	{
		cout << "Input is empty\n";
		return ;
	}

	if (displayPseudoLiteral(input))
		return;
	
	if (isChar(input))
		type = CHAR;
	else if (isFloat(input))
		type = FLOAT;
	else if (isDouble(input))
		type = DOUBLE;
	else if (isInt(input))
		type = INT;
	else
		type = UNKNOWN;

	switch (type)
	{
		case CHAR:
		{
			cout << "Input is of type CHAR\n";
			break;
		}
		case FLOAT:
		{
			cout << "Input is of type FLOAT\n";
			break;
		}
		case DOUBLE:
		{
			cout << "Input is of type DOUBLE\n";
			break;
		}
		case INT:
		{
			cout << "Input is of type INT\n";
			break;
		}
		case UNKNOWN:
		{
			cout << "Input type is UNKNOWN\n";
			break;
		}
		default:
			break;
	}
		
	return ;
}

// int a = 0;

	// std::stringstream s(input);

	// s >> a;

	// std::cout << a << '\n';