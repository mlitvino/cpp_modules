#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

class Data;

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator= (const Serializer& other);
		virtual ~Serializer() = 0;

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif
