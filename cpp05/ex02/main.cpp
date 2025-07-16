#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		ShrubberyCreationForm	ground("ground");
		Bureaucrat				Kafka("Kafka", 1);

		Kafka.signForm(ground);
		Kafka.executeForm(ground);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		RobotomyRequestForm Human("Human");
		Bureaucrat				Kafka("Kafka", 1);

		Kafka.signForm(Human);
		Kafka.executeForm(Human);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		PresidentialPardonForm hahaha("hahaha");
		Bureaucrat				Kafka("Kafka", 1);

		Kafka.signForm(hahaha);
		Kafka.executeForm(hahaha);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		PresidentialPardonForm hahaha("hahaha");
		Bureaucrat				Kafka("Kafka", 150);
		Bureaucrat				Rock("Rock", 1);

		Kafka.signForm(hahaha);
		Kafka.executeForm(hahaha);

		Rock.signForm(hahaha);
		Rock.executeForm(hahaha);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
