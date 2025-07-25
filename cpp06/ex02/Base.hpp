#ifndef BASE_HPP
#define BASE_HPP

#include <random>
#include <exception>
#include <iostream>

class Base
{
	public:
		virtual	~Base() {};
		Base*	generate();
		void	identify(Base *p);
		void	identify(Base& p);
};

#endif
