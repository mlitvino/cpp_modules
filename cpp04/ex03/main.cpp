#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int	main()
{
	Ice i1;

	std::cout << "-----\n";

	Ice *i2 = i1.clone();


	//i1.AMateria::use("dcawd");

	std::cout << "-----\n";

	delete i2;
	return 0;
}
