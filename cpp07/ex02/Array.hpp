#ifndef ARRAY_HP
#define ARRAY_HP

#include <stdexcept>

template <typename T>
class Array
{
	private:
		T		*_arr;
		size_t	_size;
	public:
		Array();
		~Array();
		Array(const Array& other);
		Array& operator= (const Array& other);

		Array(unsigned int n);
		T operator[] (size_t i);
		size_t	size();
};

#include "Array.tpp"

#endif
