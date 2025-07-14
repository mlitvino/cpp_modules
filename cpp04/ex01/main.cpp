#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

# define LOOP_N 6

int main()
{
	const Animal*	j = new Dog();
	const Animal*	x = new Cat();

	std::cout << "-----\n";

	delete j;
	delete x;

	std::cout << "-------------------\n";

	Animal *arr[LOOP_N];

	for (int i = 0; i < LOOP_N; ++i)
	{
		std::cout << "Loop i: " << i << std::endl;
		if (i < LOOP_N / 2)
		{
			arr[i] = new Dog();
		}
		else
		{
			arr[i] = new Cat();
		}
	}

	std::cout << "-----\n";

	for (int i = 0; i < LOOP_N; ++i)
	{
		std::cout << "Loop i: " << i << std::endl;
		delete arr[i];
	}

	std::cout << "-----\n";

	Dog *d1 = new Dog();
	Dog d2 = *d1;

	*d1 = *d1;

	Dog d3(d2);
	d3 = d2;

	delete d1;

	return 0;
}
