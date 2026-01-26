#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	public:
		static void convert(const std::string& input);

	private:
		ScalarConverter();
		~ScalarConverter();

		static bool isPseudoLiteral(const std::string& input);
		static bool displayPseudoLiteral(const std::string& input);

		static bool isFloat(const std::string& input);
		static bool hasExactlyOneDot(const std::string& input);

};

#endif