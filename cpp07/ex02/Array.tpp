#include "Array.hpp"

template<typename T>
Array<T>::Array(unsigned int n)
	: _arr{new T[n]()}
	, _size{n}
{}

template<typename T>
T& Array<T>::operator[] (size_t i)
{
	if (i >= _size)
		throw std::out_of_range("index outside the bounds of the array");
	return _arr[i];
}

template<typename T>
size_t Array<T>::size()
{
	return _size;
}

// Orthodox Canonical Form

template<typename T>
Array<T>::Array()
	: _arr{new T[1]()}
	, _size{1}
{}

template<typename T>
Array<T>::~Array()
{
	delete[] _arr;
	_size = 0;
}

template<typename T>
Array<T>::Array(const Array& other)
	: _arr{nullptr}
	, _size{0}
{
	*this = other;
}

template<typename T>
Array<T>& Array<T>::operator= (const Array& other)
{
	T* temp = new T[other._size]();
	for (size_t i = 0, end = other._size; i != end; ++i)
	{
		temp[i] = other._arr[i];
	}
	delete[] _arr;
	_arr = temp;
	_size = other._size;
	return *this;
}
