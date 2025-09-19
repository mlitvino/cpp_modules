#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
size_t easyfind(T& cont, int toFind)
{
	auto it = std::find(cont.begin(), cont.end(), toFind);
	if (it == cont.end())
		return -1;
	return std::distance(cont.begin(), it);
}

#endif
