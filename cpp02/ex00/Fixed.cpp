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

Fixed& Fixed::operator= (const Fixed &obj)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	this->_nbr = obj.getRawBits();
	return *this;
}

Fixed::Fixed(void)
	: _nbr{0}
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
