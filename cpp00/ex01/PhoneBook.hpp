#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

#define MAX_CONTACT 2

class	PhoneBook
{
	private:
		Contact		contacts[MAX_CONTACT];
		int			size = 0;
		int			oldest = 0;
	public:
		void		display_contact();
		void		display_contact(Contact& contact, int i);
		void		process_input(std::string& input);
		void		add();
		void		search();
};

#endif
