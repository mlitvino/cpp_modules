#include "Bureaucrat.hpp"

int	main()
{
	Bureaucraft	Kafka("Kafka");

	std::cout << Kafka << std::endl;

	Kafka.increaseGrade();

	std::cout << Kafka << std::endl;

	return 0;
}
