#include "Fixed.hpp"

int	Fixed::getRawBits(void) const
{
	return _nbr;
}

void Fixed::setRawBits(int const raw)
{
	_nbr = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_nbr) / (1 << _fract);
}

int	Fixed::toInt(void) const
{
	return _nbr >> _fract;
}

std::ostream&	operator<< (std::ostream& cout, const Fixed& obj)
{
	cout << obj.toFloat();
	return cout;
}

const Fixed&	Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}

Fixed&	Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}

const Fixed&	Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 < obj2 ? obj1 : obj2);
}

Fixed&	Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1 < obj2 ? obj1 : obj2);
}

// Increment/decrement

Fixed&	Fixed::operator++ ()
{
	++_nbr;
	return *this;
}

Fixed	Fixed::operator++ (int)
{
	Fixed new_copy(*this);

	++_nbr;
	return new_copy;
}

Fixed&	Fixed::operator-- ()
{
	--_nbr;
	return *this;
}

Fixed	Fixed::operator-- (int)
{
	Fixed new_copy(*this);

	--_nbr;
	return new_copy;
}

// Arithmetic overloading operators

Fixed Fixed::operator+ (const Fixed &nbr)
{
	Fixed calc;
	calc.setRawBits(_nbr + nbr.getRawBits());
	return calc;
}

Fixed Fixed::operator- (const Fixed &nbr)
{
	Fixed calc;
	calc.setRawBits(_nbr - nbr.getRawBits());
	return calc;
}

Fixed Fixed::operator* (const Fixed &nbr)
{
	Fixed calc;
	long temp = (long)_nbr * nbr.getRawBits();
	calc.setRawBits(int(temp >> _fract));
	return calc;
}

Fixed Fixed::operator/ (const Fixed &nbr)
{
	Fixed calc;
	long temp = (long)_nbr << _fract;
	calc.setRawBits(int(temp / nbr.getRawBits()));
	return calc;
}

// Comparion overloadong operators

bool	Fixed::operator> (const Fixed &nbr) const
{
	return _nbr > nbr._nbr;
}

bool	Fixed::operator< (const Fixed &nbr) const
{
	return _nbr < nbr._nbr;
}

bool	Fixed::operator>= (const Fixed &nbr) const
{
	return _nbr >= nbr._nbr;
}

bool	Fixed::operator<= (const Fixed &nbr) const
{
	return _nbr <= nbr._nbr;
}

bool	Fixed::operator== (const Fixed &nbr) const
{
	return _nbr == nbr._nbr;
}

bool	Fixed::operator!= (const Fixed &nbr) const
{
	return _nbr != nbr._nbr;
}

// Constructors + Deconstructor

Fixed& Fixed::operator= (const Fixed &fixed)
{
	if (this == &fixed)
		return *this;
	this->_nbr = fixed.getRawBits();
	return *this;
}

Fixed::Fixed(void) : _nbr{0} {}

Fixed::Fixed(const int nbr)
{
	_nbr = nbr << _fract;
}

Fixed::Fixed(const float nbr)
{
	_nbr = std::roundf(nbr * (1 << _fract));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed(void) {}
