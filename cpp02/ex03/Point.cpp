#include "Point.hpp"

float Point::getX() const
{
	return _x.toFloat();
}

float Point::getY() const
{
	return _y.toFloat();
}

// Constructors + Deconstructor

Point::Point() : _x{0}, _y{0} {}

Point::Point(const Fixed& x, const Fixed& y) : _x{x}, _y{y} {}

Point& Point::operator= (const Point &Point)
{
	if (this == &Point)
		return *this;
	return *this;
}

Point::Point(const Point &Point)
	: _x{Point.getX()}
	, _y{Point.getY()}
{
	*this = Point;
}

Point::~Point() {}
