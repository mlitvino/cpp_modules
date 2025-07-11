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

Fixed& Fixed::operator= (const Fixed &obj)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	this->_nbr = obj.getRawBits();
	return *this;
}

std::ostream&	operator<< (std::ostream& cout, const Fixed& obj)
{
	cout << obj.toFloat();
	return cout;
}

Fixed::Fixed(void)
	: _nbr{0}
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	_nbr = nbr << _fract;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	_nbr = std::roundf(nbr * (1 << _fract));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
