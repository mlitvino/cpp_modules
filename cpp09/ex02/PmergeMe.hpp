#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		double				_vecTime;
		void	sortVector();
	public:
		void	getInput(char **av);
		void	sortAll();
		void	printResult(char **av);
		PmergeMe();
};

#endif
