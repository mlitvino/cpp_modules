#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	std::iterator<std::forward_iterator_tag, T, T, T*, T> iterator;
};

#endif
