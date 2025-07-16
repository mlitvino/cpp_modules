#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Intern intern;
		AForm* t1;

		t1 = intern.makeForm("cheeseburger", "me");

		std::cout << t1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		Intern intern;
		AForm* t1;

		t1 = intern.makeForm(PARDON_FORM_NAME, "me");

		std::cout << *t1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return 0;
}
