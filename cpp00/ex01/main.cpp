#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout << "Type command: ";
		std::cin >> input;;
		if (std::cin.eof() || input == "EXIT")
			break ;
		phonebook.process_input(input);
	}
	if (std::cin.eof())
		std::cout << std::endl;
	return 0;
}
