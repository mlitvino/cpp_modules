#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "iomanip"

int main()
{
	DiamondTrap Galactus("Galactus");

	std::cout << std::setfill('-') << std::setw(20) << "-" << std::endl;

	Galactus.highFivesGuys();
	Galactus.guardGate();
	Galactus.attack("The Earth");
	Galactus.whoAmI();

	std::cout << std::setw(20) << "-" << std::endl;
	std::cout << std::setfill(' ');

	return 0;
}
