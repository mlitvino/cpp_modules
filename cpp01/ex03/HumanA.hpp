#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanA(const std::string name, Weapon& weapon);
		void setWeapon(Weapon &weapon);
		void attack(void);
};

#endif
