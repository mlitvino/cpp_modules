#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	//ClapTrap	toy("Toy");
	ScavTrap	robot("Robot");

	robot.guardGate();
	robot.attack("Vampire");

	return 0;
}
