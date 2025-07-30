#include "RPN.hpp"

void	RPN::fillIn(std::string arg)
{
	std::string ops = OPS;

	for (auto it = arg.begin(), end = arg.end(); it != end; ++it)
	{
		if (!std::isdigit(*it) || ops.find(*it) == std::string::npos)
			throw std::invalid_argument("Error: invalid character in argument");
		_stack.push(*it);
		
	}
}

// Orthodox Canonical Form

RPN::RPN()
	: _stack{}
{

}
