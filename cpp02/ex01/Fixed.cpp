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

Fixed& Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &fixed)
		return *this;
	this->_nbr = fixed.getRawBits();
	return *this;
}

std::ostream&	operator<< (std::ostream& cout, const Fixed& fixed)
{
	cout << fixed.toFloat();
	return cout;
}

Fixed::Fixed(void)
	: _nbr{0}
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
	: _nbr{0}
{
	_nbr = nbr << _fract;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr)
	: _nbr{0}
{
	_nbr = std::roundf(nbr * (1 << _fract));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
