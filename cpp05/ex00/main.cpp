#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat Kafka("Kafka", 6000);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		Bureaucrat Kafka("Kafka", -15);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		Bureaucrat Kafka("Kafka", 4);

		for (int i = 0;  i < 100; ++i)
		{
			std::cout << "Loop i: " << i << std::endl;
			Kafka.increaseGrade();
			std::cout << Kafka << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------" << std::endl;

	try
	{
		Bureaucrat Kafka("Kafka", 148);

		for (int i = 0;  i < 100; ++i)
		{
			std::cout << "Loop i: " << i << std::endl;
			Kafka.decreaseGrade();
			std::cout << Kafka << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
