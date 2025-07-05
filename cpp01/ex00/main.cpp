#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1 = newZombie("Boba");

	z1->announce();
	randomChump("Robert");
	delete z1;

	return 0;
}
