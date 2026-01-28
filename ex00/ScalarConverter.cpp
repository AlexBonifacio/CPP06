
#include "ScalarConverter.hpp"
#include <iostream> // std::cout 
#include <cstdlib> // std::atoi, std::atof
#include <cctype> // std::isdigit, std::isprint
#include <iomanip> // std::setprecision
#include <limits> // std::numeric_limits
#include <cmath> // std::isnan, std::isinf
#include <climits> // INT_MIN MAX

using std::cout;

bool ScalarConverter::isPseudoLiteral(const std::string& input)
{
	const std::string pLiterals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	int i = 0;
	while(i < 6 && pLiterals[i] != input)
		i++;

	if (i == 6)
	{
		return false;
	}

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

void ScalarConverter::displayChar(double input)
{

	if (std::isnan(input) || std::isinf(input))
	{
		cout << "char: impossible\n";
		return;
	}
	else if (input < 0.0 || input > 127.0)
	{
		cout << "char: Non displayable\n";
		return;
	}
	else if (!std::isprint(static_cast<unsigned char>(input)))
	{
		cout << "char: Non displayable\n";
		return;
	}
	
	cout << "char: '" << static_cast<char>(input) << "'\n";

}

void ScalarConverter::displayInt(double input)
{
	if (std::isnan(input) || std::isinf(input))
	{
		cout << "int: impossible\n";
		return;
	}

	if (input < static_cast<double>(std::numeric_limits<int>::min())
		|| input > static_cast<double>(std::numeric_limits<int>::max()))
	{
		cout << "int: impossible\n";
		return;
	}
	
	int i = static_cast<int>(input);

	cout << "int: " << i << "\n";
}

void ScalarConverter::displayFloat(double input)
{
	float f = static_cast<float>(input);

	if (std::isnan(f))
	{
		cout << "float: nanf\n";
	}
	else if (std::isinf(f))
	{
		if (f < 0.0f)
			cout << "float: -inff\n";
		else
			cout << "float: +inff\n";
	}
	else
	{
		std::ios::fmtflags old_flags = std::cout.flags();
		std::streamsize old_precision = std::cout.precision();
		
		cout << std::fixed << std::setprecision(1);
		cout << "float: " << f << "f\n";

		std::cout.flags(old_flags);
		std::cout.precision(old_precision);
	}
}

void ScalarConverter::displayDouble(double input)
{
	if (std::isnan(input))
	{
		cout << "double: nan\n";
	}
	else if (std::isinf(input))
	{
		if (input < 0.0)
			cout << "double: -inf\n";
		else
			cout << "double: +inf\n";
	}
	else
	{
		std::ios::fmtflags old_flags = std::cout.flags();
		std::streamsize old_precision = std::cout.precision();

		cout << std::fixed << std::setprecision(1);
		cout << "double: " << input << "\n";

		std::cout.flags(old_flags);
		std::cout.precision(old_precision);
	}
}

void ScalarConverter::displayAll(double input)
{
	displayChar(input);
	displayInt(input);
	displayFloat(input);
	displayDouble(input);
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
			char value = input[0];
			displayAll(static_cast<double>(value));
			break;
		}
		case FLOAT:
		{
			float f = std::strtof(input.c_str(), NULL);
			double value = static_cast<double>(f);
			displayAll(value);
			break;
		}
		case DOUBLE:
		{
			double value = std::strtod(input.c_str(), NULL);
			displayAll(value);
			break;
		}
		case INT:
		{
			int i;
			if (!parseIntStrict(input, i))
			{
				double value = std::strtod(input.c_str(), NULL);
				displayAll(value);
				break;
			}
			displayAll(static_cast<double>(i));
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

bool ScalarConverter::parseIntStrict(const std::string& input, int& out)
{
	char* end = NULL;
	long v;

	if (input.empty())
		return false;

	errno = 0;
	v = std::strtol(input.c_str(), &end, 10);

	if (end == input.c_str() || *end != '\0')
		return false;

	if (errno == ERANGE)
		return false;

	if (v < INT_MIN || v > INT_MAX)
		return false;

	out = static_cast<int>(v);
	return true;
}