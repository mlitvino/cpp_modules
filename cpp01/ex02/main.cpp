#include <string>
#include <iostream>

int	main(void)
{
	// Init
	std::string	str = "HI THIS IS BRAIN";
	std::string	*str_ptr = &str;
	std::string &str_ref = str;

	// Print memory address
	std::cout << "The memory adress of str:" << &str << std::endl;
	std::cout << "The memory adress of str_ptr:" << str_ptr << std::endl;
	std::cout << "The memory adress of str_ref:" << &str_ref << std::endl;

	// Print value
	std::cout << "The value of str:" << str << std::endl;
	std::cout << "The value of str_ptr:" << *str_ptr << std::endl;
	std::cout << "The value of str_ref:" << str_ref << std::endl;

	return 0;
}
