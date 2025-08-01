#include "PmergeMe.hpp"

void	PmergeMe::printResult(char **av)
{
	std::cout << "Before: ";
	for (int i = 0; av[i]; ++i)
		std::cout << av[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (auto &pair : _vec)
	{
		std::cout << pair.first << " " << pair.second << " ";
	}
	if (_tailVal.has_value())
		std::cout << _tailVal.value();
	std::cout << std::endl;

	std::cout
	<< "Time to process a range of " << (_vec.size() * 2 + _tailVal.has_value())
	<< " elements with std::vector : " << _vecTime << " us"
	<< std::endl;
}

void	PmergeMe::getInput(char **av)
{
	for (int i = 0; av[i]; i += 2)
	{
		if (!av[i + 1])
		{
			_tailVal = std::stoi(av[i]);
			break ;
		}
		int	first = std::stoi(av[i]);
		int	second = std::stoi(av[i + 1]);
		if (first < 0 || second < 0)
			throw std::runtime_error("Error: argument not positive number");
		if (first < second)
			std::swap(first, second);
		_vec.push_back(std::make_pair(first, second));
	}
	sortVector();
	printResult(av);
}

void	PmergeMe::sortVector()
{
	std::sort(_vec.begin(), _vec.end());
}

// Orthodox Canonical Form

PmergeMe::PmergeMe()
	: _vec{}
	, _vecTime{0}
	, _tailVal{std::nullopt}
{}
