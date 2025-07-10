#ifndef BRAIN_HPP
#define BRAIN_HPP

#define AMOUNT_IDEAS 100

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string	ideas[AMOUNT_IDEAS];
	public:
		Brain();
		~Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
};

#endif
