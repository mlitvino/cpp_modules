#include <string>
#include <iostream>

int	main(void)
{
	// Init
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string &stringREF = string;

	// Print memory address
	std::cout << "The memory adress of stringORG:" << &string << std::endl;
	std::cout << "The memory adress of stringPTR:" << stringPTR << std::endl;
	std::cout << "The memory adress of stringREF:" << &stringREF << std::endl;

	// Print value
	std::cout << "The value of stringORG:" << string << std::endl;
	std::cout << "The value of stringPTR:" << *stringPTR << std::endl;
	std::cout << "The value of stringREF:" << stringREF << std::endl;

	return 0;
}
