#include "Intern.hpp"

AForm* Intern::makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	for (int i = 0; i < MAX_FORMS; ++i)
	{
		if (name == formNames[i])
		{
			std::cout << "Inter creates " << name << std::endl;
			return (this->*formCtors[i])(target);
		}
	}
	throw NoSuchFormException();
}

// Orthodox Canonical

Intern::Intern()
	: formNames
	{
		PARDON_FORM_NAME ,
		SHRUB_FORM_NAME ,
		ROBOT_FORM_NAME ,
	}
	, formCtors
	{
		&Intern::makePresidential ,
		&Intern::makeShrubbery ,
		&Intern::makeRobotomy ,
	}
{}

Intern::~Intern() {}

Intern::Intern(const Intern& obj)
	: Intern()
{
	*this = obj;
}

Intern& Intern::operator= (const Intern& obj)
{
	if (this == &obj)
		return *this;
	for (int i = 0; i < MAX_FORMS; ++i)
	{
		formNames[i] = obj.formNames[i];
		formCtors[i] = obj.formCtors[i];
	}
	return *this;
}
