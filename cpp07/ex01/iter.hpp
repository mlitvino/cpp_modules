#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename L, typename F>
void	iter(T* array, L& len, F foo)
{
	for (L i = 0; i < len; ++i)
	{
		foo(array[i]);
	}
}

template<typename T>
void printValue(const T& x)
{
	std::cout << x << ' ';
}

template<typename T>
void	incr(T& x)
{
	x++;
}

#endif
