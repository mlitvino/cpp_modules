#include "PmergeMe.hpp"

void	PmergeMe::sortVector()
{

}

void	PmergeMe::printResult(char **av)
{
	std::cout << "Before: ";
	for (int i = 0; av[i]; ++i)
		std::cout << av[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (int &val : _vec)
		std::cout << val << " ";
	std::cout << std::endl;

	std::cout
	<< "Time to process a range of " << _vec.size()
	<< " elements with std::vector : " << _vecTime << " us"
	<< std::endl;
}

void	PmergeMe::getInput(char **av)
{
	for (int i = 0; av[i]; ++i)
	{
		int	temp = std::stoi(av[i]);
		if (temp < 0)
			throw std::runtime_error("Error: number must be positive");
		_vec.push_back(temp);
	}
	sortVector();
}

// Orthodox Canonical Form

PmergeMe::PmergeMe()
	: _vec{}
	, _vecTime{0}
{}
