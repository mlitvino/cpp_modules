#include "Contact.hpp"

void	Contact::fill_in(void)
{
	std::cout << "Type first name: ";
	std::cin >> first_name;
	std::cout << "Type last name: ";
	std::cin >> last_name;
	std::cout << "Type nickname: ";
	std::cin >> nickname;
	std::cout << "Type phone number: ";
	std::cin >> phone_number;
	std::cout << "Type darkest secret: ";
	std::cin >> phone_number;
}

std::string	Contact::getFirstName()
{
	return first_name;
}

std::string Contact::getLastName()
{
	return last_name;
}

std::string	Contact::getNickname()
{
	return nickname;
}
