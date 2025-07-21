#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

// Orthodox Canonical Form

template <typename T>
MutantStack<T>::~MutantStack() {};

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
	: std::stack<T>(other)
{}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	this->c = other.c;
	return *this;
}

