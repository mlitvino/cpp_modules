#include <iostream>
#include <cstring>
#include "iter.hpp"

int main()
{
	std::cout << "---------" << std::endl;

	const char *str = "rome\n";
	std::size_t len = std::strlen(str);

	iter(str, len, &printValue<char>);

	std::cout << "---------" << std::endl;

	// test int array
	std::cout << "Test int array:" << std::endl;
	int intArr[] = {0, 1, 2, 3, 4};
	std::size_t intLen = sizeof(intArr) / sizeof(intArr[0]);
	iter(intArr, intLen, printValue<int>);
	std::cout << std::endl;
	iter(intArr, intLen, incr<int>);
	iter(intArr, intLen, printValue<int>);
	std::cout << std::endl;

	std::cout << "---------" << std::endl;

	// test float array
	std::cout << "Test float array:" << std::endl;
	float floatArr[] = {0.5f, 1.5f, 2.5f};
	std::size_t floatLen = sizeof(floatArr) / sizeof(floatArr[0]);
	iter(floatArr, floatLen, printValue<float>);
	std::cout << std::endl;
	iter(floatArr, floatLen, incr<float>);
	iter(floatArr, floatLen, printValue<float>);
	std::cout << std::endl;

	std::cout << "---------" << std::endl;

	// test double array
	std::cout << "Test double array:" << std::endl;
	double dblArr[] = {3.14, 6.28, 9.42, 12.56};
	std::size_t dblLen = sizeof(dblArr) / sizeof(dblArr[0]);
	iter(dblArr, dblLen, printValue<double>);
	std::cout << std::endl;
	iter(dblArr, dblLen, incr<double>);
	iter(dblArr, dblLen, printValue<double>);
	std::cout << std::endl;

	return 0;
}
