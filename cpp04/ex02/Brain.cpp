#include "Brain.hpp"

// Constructors + Destructor

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
	for (std::string& idea : ideas)
		idea = "nothing";
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << "Brain: Copy assignment constructor called" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < AMOUNT_IDEAS; ++i)
		ideas[i] = obj.ideas[i];
	return *this;
}
