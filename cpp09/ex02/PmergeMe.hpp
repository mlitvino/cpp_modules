#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#define INIT_PAIR_SIZE 2

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_list;
		double				_vecTime;


		char				**_av;
	public:
		PmergeMe();

		void	parseInput(char **av);
		void	insert(int pair_size);
		void	sortPairs(int pair_size);
		void	printResult(char **av);
};

#endif
