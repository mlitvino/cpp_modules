#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon sword = Weapon("sword");
		HumanA Jesus("Jesus", sword);

		Jesus.attack();
		sword.setType("bloody sword");
		Jesus.attack();
	}
	{
		Weapon spike = Weapon("spike");
		HumanB Devil("Devil");

		Devil.setWeapon(spike);
		Devil.attack();
		spike.setType("broken spike");
		Devil.attack();
	}
	return 0;
}

// int main()
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);

// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB jim("Jim");

// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// 	return 0;
// }
