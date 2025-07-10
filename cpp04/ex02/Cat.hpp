#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include "iostream"
#include "string.h"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		void	makeSound() const;
};

#endif
