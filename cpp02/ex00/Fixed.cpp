#include "Fixed.hpp"

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return _nbr;
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &fixed)
		return *this;
	Fixed new_fixed;
	new_fixed._nbr = fixed.getRawBits();
	return *this;
}

Fixed::Fixed(void)
	: _nbr{0}
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
	: _nbr{fixed._nbr}
{
	std::cout << "Copy constructor called" << std::endl;
}
