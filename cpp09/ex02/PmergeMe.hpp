#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <optional>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<std::pair<int,int>>	_vec;
		double				_vecTime;
		std::optional<int>	_tailVal;
		void	sortVector();
	public:
		void	getInput(char **av);
		void	sortAll();
		void	printResult(char **av);
		PmergeMe();
};

#endif
