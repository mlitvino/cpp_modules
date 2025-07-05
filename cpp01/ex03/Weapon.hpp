#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string new_type);
		Weapon(void);
		const std::string& getType(void);
		void	setType(std::string	new_type);
};

#endif
