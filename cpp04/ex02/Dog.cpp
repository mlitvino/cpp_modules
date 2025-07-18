#include "Dog.hpp"

void	Dog::makeSound() const
{
	std::cout << "Dog: makeSound: bark bark bark!!!" << std::endl;
}

// Constructors + Destructor

Dog::Dog()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog& obj)
	: Animal()
	, brain(new Brain(*obj.brain))
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	type = obj.type;
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	type = obj.type;
	delete brain;
	brain = new Brain(*obj.brain);
	return *this;
}
