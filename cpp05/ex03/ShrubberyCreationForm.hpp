#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <fstream>

#define SHRUB_FORM_SIGN 145
#define SHRUB_FORM_EXEC 137
#define SHRUB_FORM_NAME "shrubbery creation"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& obj);

		ShrubberyCreationForm(const std::string& target);
		void	executeForm() const override;

	class FailedToOpenException : public std::exception
	{
		public:
			const char* what() const noexcept override
			{
				return "The form failed to open file!";
			}
	};
};


#endif
