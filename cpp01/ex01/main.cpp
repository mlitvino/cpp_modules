#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde = zombieHorde(HORDE_SIZE, HORDE_NAME);

	for (int i = 0; i < HORDE_SIZE; i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}
