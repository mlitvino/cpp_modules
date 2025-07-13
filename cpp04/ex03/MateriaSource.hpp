#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#include <string>
#include <iostream>

#define MAX_SLOT 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inv[MAX_SLOT];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator= (const MateriaSource& obj);
		virtual ~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
