#include "Span.hpp"

#include <iostream>

void Span::addNumber(int n)
{
	if (_size == _cap)
		throw std::length_error("no space left in array");
	_arr[_size++] = n;
}

int Span::shortestSpan()
{
	if (_size < 2)
		throw std::length_error("no elements to find span");
	std::vector<int> tmp(_arr.begin(), _arr.begin() + _size);
	std::sort(tmp.begin(), tmp.end());

	size_t	minDist = std::numeric_limits<size_t>::max();
	for (size_t i = 1; i < tmp.size(); ++i)
	{
		size_t diff = abs(tmp[i] - tmp[i-1]);
		if (diff < minDist)
			minDist = diff;
	}
	return minDist;
}

int Span::longestSpan()
{
	if (_size < 2)
		throw std::length_error("no elements to find span");
	auto minmax = std::minmax_element(_arr.begin(), _arr.begin() + _size);
	return std::abs(*minmax.second - *minmax.first);
}

void	Span::addManyNumbers(int nAmount)
{
	srand(time(NULL));
	for (size_t i = _size; nAmount > 0; ++i)
	{
		addNumber(rand());
		--nAmount;
	}
}

Span::Span(unsigned int N)
	: _arr(N)
	, _size{0}
	, _cap{N}
{}

// Orthodox Canonical Form

Span::~Span() {}

Span::Span()
	: _arr{0}
	, _size{0}
	, _cap{0}
{}

Span::Span(const Span& other)
	: Span()
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;
	_arr = other._arr;
	_size = other._size;
	_cap = other._cap;
	return *this;
}
