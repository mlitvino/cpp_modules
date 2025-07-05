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
