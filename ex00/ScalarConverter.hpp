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

		static bool isChar(const std::string& input);
		static bool isInt(const std::string& input);
		static bool isFloat(const std::string& input);
		static bool isDouble(const std::string& input);
		static bool hasExactlyOneDot(const std::string& input);

		static void displayAll(double input);
		static void displayChar(double input);
		static void displayInt(double input);
		static void displayFloat(double input);
		static void displayDouble(double input);

		static bool parseIntStrict(const std::string& s, int& out);

		enum Type
		{
			CHAR,
			PSEUDO_LITERAL,
			FLOAT,
			DOUBLE,
			INT,
			UNKNOWN
		};

};

#endif