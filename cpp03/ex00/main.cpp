#include "ClapTrap.hpp"

int main()
{
	ClapTrap butthead("Butthead");
	ClapTrap beavis("Beavis");

	for (int round = 1; round <= 4; ++round) {
		std::cout << "[Round " << round << "]\n";
		butthead.attack("Beavis");
		beavis.takeDamage(0);
		beavis.attack("Butthead");
		butthead.takeDamage(0);
	}

	std::cout << "\n-- Repair: Heroes repairs until energy runs out --\n";
	for (int attempt = 5; attempt <= 11; ++attempt) {
		std::cout << "[Repair " << attempt << "]\n";
		beavis.beRepaired(5);
	}

	return 0;
}
