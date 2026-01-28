#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // uintptr_t
#include <string>

struct Data {
	int			n;
	std::string s;
};


class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		~Serializer();


};
#endif