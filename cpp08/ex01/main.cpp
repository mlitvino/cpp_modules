#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec = {-1, 2, 3, 4, 5};
	Span sp(vec.size());

	for (auto &c : vec)
	{
		sp.addNumber(c);
	}
	std::cout << "Span: "; sp.printValues();

	std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cerr << "Expected exception (addNumber): " << e.what() << std::endl;
	}

	Span sp2(1);
	sp2.addNumber(100);
	try {
		sp2.shortestSpan();
	} catch (const std::exception& e) {
		std::cerr << "Expected exception (shortestSpan): " << e.what() << std::endl;
	}

	try {
		sp2.longestSpan();
	} catch (const std::exception& e) {
		std::cerr << "Expected exception (longestSpan): " << e.what() << std::endl;
	}


	std::list<int> list = {1, 2, 3, 4, 5};
	std::vector<int> vec2 = {10, 20, 30, 40, 50};
	Span sp3(100);
	Span sp4(7);

	for (auto &c : vec2)
	{
		sp3.addNumber(c);
		sp4.addNumber(c);
	}

	sp3.insertRange(1, list.begin(), list.end());
	std::cout << "Span3: "; sp3.printValues();


	try
	{
		sp4.insertRange(1, list.begin(), list.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Expected exception (insertRange): " << e.what() << '\n';
	}
	std::cout << "Span4: "; sp4.printValues();

	return 0;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
