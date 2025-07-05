#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": destructor is called" << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
}
