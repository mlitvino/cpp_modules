#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

#define OPS "+-/*"

class RPN
{
	private:
		std::stack<int>	_stack;
	public:
		RPN();
		void	fillIn(std::string arg);
};

#endif
