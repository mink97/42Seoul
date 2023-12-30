#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
	private:

	public:
		Serializer();
		Serializer(const Serializer& ref);
		~Serializer();

		Serializer&	operator=(const Serializer& ref);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
