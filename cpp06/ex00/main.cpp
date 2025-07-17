#include "ScalarConverter.hpp"

int main()
{
	// std::string input;

	// while (1)
	// {
	// 	std::cout << "Type command: ";
	// 	std::cin >> input;
	// 	if (std::cin.eof())
	// 		break ;
	// 	ScalarConverter::convert(input);
	// }
	// if (std::cin.eof())
	// 	std::cout << std::endl;


	float f = std::stof("nan");

	std::cout << "f: " << f << std::endl;

	int i = static_cast<int>(f);

	std::cout << "i: " << i << std::endl;

	// int j = std::stoi("nan");

	// std::cout << "j: " << j << std::endl;

	long double d = std::stod("-214748456464867168718643648");

	std::cout << "d: " << d << std::endl;

	return 0;
}
