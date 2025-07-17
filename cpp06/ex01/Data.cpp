#include "Data.hpp"

Data::Data() : x{1}, y{2} {}

Data::~Data() {}

Data::Data(const Data& obj)
{
	*this = obj;
}

Data& Data::operator= (const Data& obj)
{
	if (this == &obj)
		return *this;
	x = obj.x;
	y = obj.y;
	return *this;
}
