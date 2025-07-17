#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

// Orthodox Canonical Form

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& obj)
{
	*this = obj;
}

Serializer& Serializer::operator= (const Serializer& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}
