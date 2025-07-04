#include "PhoneBook.hpp"
#include "Contact.hpp"

void	PhoneBook::add()
{
	Contact new_contact;

	new_contact.fill_in();
	contacts[oldest] = new_contact;
	if (++oldest == MAX_CONTACT)
		oldest = 0;
	if (size < MAX_CONTACT)
		size++;
	std::cout << "You successfully added a new contact!" << std::endl;
}

std::string	fit(const std::string &str)
{
	if (str.size() > 10)
	{
		return str.substr(0, 10-1) + '.';
	}
	else
		return str;
}

void	PhoneBook::display_contact()
{
	std::cout << std::string(44, '-') << '\n';
	std::cout
	<< "|" << std::setw(10) << "index" << "|"
	<< std::setw(10) << "first name" << "|"
	<< std::setw(10) << "last name" << "|"
	<< std::setw(10) << "nickname" << "|\n";
	std::cout << std::string(44, '-') << '\n';
}

void	PhoneBook::display_contact(Contact& contact, int i)
{
	std::cout
	<< "|" << std::setw(10) << i << "|"
	<< std::setw(10) << fit(contact.getFirstName()) << "|"
	<< std::setw(10) << fit(contact.getLastName()) << "|"
	<< std::setw(10) << fit(contact.getNickname()) << "|\n";
}

void	PhoneBook::search(void)
{
	int	to_find;

	display_contact();
	for (int i = 0; i < size; i++)
		display_contact(contacts[i], i);
	std::cout << std::string(44, '-') << '\n';
	std::cout << "Type index to show contact info: ";
	if (!(std::cin >> to_find)
		|| to_find < 0 || to_find >= size)
	{
		if (std::cin.eof())
			return ;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Warning: invalid index" << std::endl;
	}
	else
	{
		display_contact(contacts[to_find], to_find);
	}
}

void	PhoneBook::process_input(std::string &input)
{
	if (input == "ADD")
		add();
	else if (input == "SEARCH")
		search();
	else
		std::cout << "Warning: non-existent command" << std::endl;
}


