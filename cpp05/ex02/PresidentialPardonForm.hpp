#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#include <string>
#include <iostream>

#define PARDON_FORM_SIGN 25
#define PARDON_FORM_EXEC 5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator= (const PresidentialPardonForm& obj);

		PresidentialPardonForm(const std::string& target);
		void	executeForm() const override;
};

#endif
