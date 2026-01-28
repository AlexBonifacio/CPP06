
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data *data = new Data;

	uintptr_t raw = Serializer::serialize(data);

	std::cout << "Serialized data address: " << raw << "\n";

	std::cout << "Serialized data address: " << reinterpret_cast<void*>(raw) << "\n";

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized data address: " << reinterpret_cast<uintptr_t>(deserializedData) << "\n";
	std::cout << "Deserialized data address: " << deserializedData << "\n";


	if (data == deserializedData)
		std::cout << "Success: original and deserialized pointers match.\n\n";
	else
		std::cout << "Error: original and deserialized pointers do not match.\n\n";

	/*----------------------------------------------------------------------*/
	std::cout << "Modifying the raw value and checking again...\n";
	raw++;
	deserializedData = Serializer::deserialize(raw);
	if (data == deserializedData)
		std::cout << "Success: original and deserialized pointers match.\n";
	else
		std::cout << "Error: original and deserialized pointers do not match.\n";

	delete data;
	return 0;
}