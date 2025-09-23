#include "PmergeMe.hpp"

void	PmergeMe::printResult(char **av)
{
	std::cout << "Before: ";
	for (int i = 1; av[i]; ++i)
		std::cout << av[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (auto &c : _vec)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;

	std::cout
	<< "Time to process a range of " << (_vec.size())
	<< " elements with std::vector : " << _vecTime << " us"
	<< std::endl;
}

void	PmergeMe::parseInput(char **av)
{
	int	val;

			_av = av;

	for (int i = 1; av[i]; ++i)
	{
		val = std::stoi(av[i]);
		if (val < 0)
			throw std::runtime_error("Error: argument not positive number");
		if (std::find(_vec.begin(), _vec.end(), val) != _vec.end())
			throw std::runtime_error("Error: duplicate in argument list");
		_vec.push_back(val);
		_list.push_back(val);
	}
}

void	PmergeMe::insert(int pair_size)
{
	if (pair_size == 0)
		return ;

	std::cout << "Pair size: " << pair_size << std::endl;
	std::vector<int*>	main;
	std::vector<int*>	pend;

	for (int i = 0; i < pair_size; ++i)
		main.push_back(&_vec[i]);

	size_t block = pair_size;
	size_t i = block;

	for (; i + block <= _vec.size(); i += block * 2)
		for (size_t j = 0; j < block; ++j)
			main.push_back(&_vec[i + j]);

	for (i = pair_size * 2; i + block <= _vec.size(); i += block * 2)
		for (size_t j = 0; j < block; ++j)
			pend.push_back(&_vec[i + j]);

	std::cout << "main: ";
	for (auto c : main)
	{
		std::cout << *c << " ";
	}
	std::cout << std::endl;

	std::cout << "pend: ";
	for (auto c : pend)
	{
		std::cout << *c << " ";
	}
	std::cout << std::endl;


	//insert(pair_size / 2);
}

void	PmergeMe::sortPairs(int pair_size)
{
	int pairs = _vec.size() / pair_size;

	std::cout
	<< "Pairs: " << pairs << std::endl
	<< "Pair size: " << pair_size << std::endl;

	for (int i = 1; i < pairs + 1; ++i)
	{
		int& right = _vec[(i * pair_size) - 1];
		int& left = _vec[(i * pair_size) - (pair_size / 2) - 1];

		// std::cout
		// << "Loop i: " << i << std::endl
		// << "Comparing: " << left << " and " << right << std::endl;

		if (left > right)
		{
			// std::cout
			// << "right begin: " << *(_vec.begin() + (i * pair_size) - (pair_size / 2)) << std::endl
			// << "right before end: " << *(_vec.begin() + (i * pair_size) - 1) << std::endl
			// << "left begin: " << *(_vec.begin() + (i * pair_size) - pair_size) << std::endl;

			std::swap_ranges(
				_vec.begin() + (i * pair_size) - (pair_size / 2),
				_vec.begin() + (i * pair_size),
				_vec.begin() + (i * pair_size) - pair_size
			);
		}
	}
	int new_pair_size = pair_size * 2;
	if (_vec.size() / new_pair_size > 0)
		sortPairs(new_pair_size);
	std::cout << "---INSERT_START---" << std::endl;
	insert(pair_size / 2);
	std::cout << "---INSERT_END---" << std::endl;
}

// Orthodox Canonical Form

PmergeMe::PmergeMe()
	: _vec{}
	, _vecTime{0}
{}
