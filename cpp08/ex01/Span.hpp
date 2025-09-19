#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <iostream>
#include <utility>

class Span
{

	private:
		std::vector<int> _vec;
		size_t			_size;
		size_t			_cap;
	public:
		~Span();
		Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		Span(unsigned int N);
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void	printValues();

		template <typename It>
		void	insertRange(size_t pos, It begin, It end)
		{
			if (pos >= _size)
				throw std::length_error("position outside of vector");
			for (;begin != end; ++begin)
			{
				if (_size == _cap)
					throw std::length_error("no space left in vector");
				_vec.insert(_vec.begin() + pos++, *begin);
				++_size;
			}
		}
};

#endif
