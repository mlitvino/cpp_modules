#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Form form1("AD-1057960-ultra-double-cheese", 10, 65);

		std::cout << form1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		Form form1("WrongForm", -456, 650);

		std::cout << form1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		Form form1("form1", 10, 65);
		Bureaucrat	Kafka("Kafka", 11);
		Bureaucrat	Eichmann("Eichmann", 9);

		Kafka.signForm(form1);
		Eichmann.signForm(form1);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	Bureaucrat Goodman("Goodman", 12);
	Form form2("form2", 10, 10);

	Goodman.signForm(form2);

	return 0;
}
