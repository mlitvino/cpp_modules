#include "ClapTrap.hpp"

int main()
{
	ClapTrap butthead("Butthead");
	ClapTrap beavis("Beavis");

	for (int round = 1; round <= 4; ++round) {
		std::cout << "[Round " << round << "]\n";
		butthead.attack("Beavis");
		beavis.takeDamage(5);
		beavis.attack("Butthead");
		butthead.takeDamage(1);
	}

	std::cout << "\n-- Repair: Heroes repairs until energy runs out --\n";
	for (int attempt = 5; attempt <= 12; ++attempt) {
		std::cout << "[Repair " << attempt << "]\n";
		beavis.beRepaired(5);
		butthead.beRepaired(1);
	}

	return 0;
}
