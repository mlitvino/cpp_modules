#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;
#include "ICharacter.hpp"

#include <string>
#include <iostream>

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria& obj);
		AMateria& operator= (const AMateria& obj);

		AMateria(std::string const& type);
		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
