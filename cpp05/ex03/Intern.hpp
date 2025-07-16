#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define MAX_FORMS 3

class Intern
{
	private:
		std::string	formNames[MAX_FORMS];
		AForm*	(Intern::*formCtors[MAX_FORMS])(const std::string&);
	public:
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern& operator= (const Intern& obj);

		AForm*	makeShrubbery(const std::string& target);
		AForm*	makeRobotomy (const std::string& target);
		AForm*	makePresidential(const std::string& target);
		AForm*	makeForm(const std::string& name, const std::string& target);

	class NoSuchFormException : public std::exception
	{
		public:
			const char* what() const noexcept override
			{
				return "I don't know such form!!!";
			}
	};
};

#endif
