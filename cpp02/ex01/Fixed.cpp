#include "Fixed.hpp"

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _nbr;
}

void Fixed::setRawBits(int const raw)
{
	_nbr = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &fixed)
		return *this;
	this->_nbr = fixed.getRawBits();
	return *this;
}

Fixed::Fixed(void)
	: _nbr{0}
{
	std::cout << "Default constructor called" << std::endl;
}

explicit Fixed::Fixed(const int nbr)
{
	_nbr = nbr;
	std::cout << "Copy constructor called" << std::endl;
}

explicit Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
