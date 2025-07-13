#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <string>
#include <iostream>

#define MAX_SLOT 4

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inv[MAX_SLOT];
	public:
		Character();
		Character(const Character& obj);
		Character& operator= (const Character& obj);
		virtual ~Character();

		Character(const std::string& name);
		std::string const & getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif
