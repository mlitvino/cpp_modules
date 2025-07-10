#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include "iostream"
#include "string.h"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		void	makeSound() const;
};

#endif
