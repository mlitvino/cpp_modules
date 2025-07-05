#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

# define HORDE_SIZE 1
# define HORDE_NAME "FakeHuman"

class Zombie
{
	private:
		std::string	_name;
	public:
		void announce(void);
		void setName(std::string name);
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
};

Zombie*	zombieHorde( int N, std::string name );

#endif
