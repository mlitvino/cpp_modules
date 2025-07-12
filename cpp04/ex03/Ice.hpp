#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <string>
#include <iostream>

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		Ice(const Ice& obj);
		Ice& operator= (const Ice& obj);
		Ice* clone() const override;
		void use(ICharacter& target) override;
};

#endif
