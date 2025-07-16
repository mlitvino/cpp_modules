#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::executeForm() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("presidential pardon form", target, PARDON_FORM_SIGN, PARDON_FORM_EXEC)
{}

// Orthodox Canonical

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("nameless", "nameless", PARDON_FORM_SIGN, PARDON_FORM_EXEC)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	: PresidentialPardonForm()
{
	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	return *this;
}
