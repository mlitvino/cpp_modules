#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	std::cout << "-----\n";

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << "-----\n";

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "-----\n";

	delete bob;
	delete me;
	delete src;

	return 0;
}



// int	main()
// {
// 	ICharacter *wizard = new Character("Jesus");
// 	Character enemy;
// 	Ice *ice = new Ice;

// 	std::cout << "-----\n";

// 	// wizard.equip(ice);
// 	// wizard.equip(nullptr);
// 	//wizard.use(0, enemy);

// 	std::cout << "-----\n";

// 	delete wizard;
// 	delete ice;

// 	return 0;
// }
