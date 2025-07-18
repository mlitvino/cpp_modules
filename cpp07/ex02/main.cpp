#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int>	t1;
	Array<int>	t2(30);

	Array<double> t3(30);

	Array<char********> t4(123);

	t2 = t2;
	t1 = t2;

	for (int i = 0; i < 30; ++i)
	{
		std::cout << "Loop i: " << i << std::endl;
		std::cout << "t1 " << t1[i] << std::endl;
		std::cout << "t2 " << t2[i] << std::endl;
		std::cout << "t3 " << t3[i] << std::endl;
	}

	// Invalid

	//t1 = t3;
	//std::cout << t1[-1] << std::endl;
	//std::cout << t2[10] << std::endl;

	return 0;
}
