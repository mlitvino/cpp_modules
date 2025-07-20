#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <ctime>

class Span
{
	private:
		std::vector<int> _arr;
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
		void	addManyNumbers(int nAmount);

		template <typename Iterator>
		void	addManyNumbers(Iterator begin, Iterator end)
		{
			for (; begin != end; ++begin)
			{
				addNumber(*begin);
			}
		}
};

#endif
