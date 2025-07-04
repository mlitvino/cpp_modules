#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class	Contact
{
	private:
		std::string	phone_number;
		std::string	darkest_secret;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
	public:
		void	fill_in();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
};

#endif
