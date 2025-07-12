#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <string>
#include <iostream>

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();
		Cure(const Cure& obj);
		Cure& operator= (const Cure& obj);
		Cure* clone() const override;
		void use(ICharacter& target) override;
};

#endif
