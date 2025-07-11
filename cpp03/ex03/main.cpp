#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "iomanip"

int main()
{
	DiamondTrap Galactus("Galactus");

	std::cout << std::setfill('-') << std::setw(20) << "-" << std::endl;

	Galactus.whoAmI();
	Galactus.highFivesGuys();
	Galactus.guardGate();

	std::cout << std::setw(20) << "-" << std::endl;

	Galactus.attack("The Earth");
	Galactus.takeDamage(50);
	Galactus.takeDamage(49);
	Galactus.takeDamage(1);

	std::cout << std::setw(20) << "-" << std::endl;
	std::cout << std::setfill(' ');

	return 0;
}
