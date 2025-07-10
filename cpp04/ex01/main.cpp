#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal*	j = new Dog();
	const Animal*	x = new Cat();

	std::cout << "-----\n";

	delete j;
	delete x;

	std::cout << "-------------------\n";

	Animal *arr[10];

	std::cout << "-----\n";

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Loop i: " << i << std::endl;
		if (i < 10 / 2)
		{
			arr[i] = new Dog();
		}
		else
		{
			arr[i] = new Cat();
		}
	}

	std::cout << "-----\n";

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Loop i: " << i << std::endl;
		delete arr[i];
	}

	return 0;
}
