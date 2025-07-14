#include "Bureaucrat.hpp"

int	main()
{
	Bureaucraft	Kafka("Kafka", 200);

	std::cout << Kafka << std::endl;

	Kafka.decreaseGrade();

	std::cout << Kafka << std::endl;

	return 0;
}
