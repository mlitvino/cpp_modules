#include "WrongCat.hpp"

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: makeSound: meEEEEoooOOooow!" << std::endl;
}

// Constructors + Destructor

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	type = obj.type;
	std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "WrongCat: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	type = obj.type;
	return *this;
}
