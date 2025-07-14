#include "Bureaucrat.hpp"

// void	Bureaucraft::GradeTooHighException()
// {
// 	std::cout
// 	<< "Exception: " << _name << " has a grade " << _grade
// 	<< ". It's too high to decrease!"
// 	<< std::endl;
// }

// void	Bureaucraft::GradeTooLowException()
// {
// 	std::cout
// 	<< "Exception: " << _name << " has a grade " << _grade
// 	<< ". It's too low to decrease!"
// 	<< std::endl;
// }

const std::string&	Bureaucraft::getName() const
{
	return _name;
}

int		Bureaucraft::getGrade() const
{
	return _grade;
}

void	Bureaucraft::increaseGrade()
{
	try {
		if (_grade - 1 < MAX_GRADE)
			throw GradeTooLowException();
		--_grade;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucraft::decreaseGrade()
{
	try {
		if (_grade + 1 > MIN_GRADE)
			throw GradeTooHighException();
		++_grade;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucraft& obj)
{
	out << obj.getName() << ", bureacraft grade " << obj.getGrade();
	return out;
}

Bureaucraft::Bureaucraft(const std::string& name)
	: _name{name}
	, _grade{75}
{}

Bureaucraft::Bureaucraft(const std::string& name, int grade)
	: Bureaucraft(name)
{
	try {
		if (grade > MIN_GRADE)
			throw GradeTooLowException();
		if (grade < MAX_GRADE)
			throw GradeTooHighException();
		_grade = grade;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

// Orthodox Canonical Form

Bureaucraft::Bureaucraft()
	: _name{"nameless"}
	, _grade{150}
{}

Bureaucraft::Bureaucraft(const Bureaucraft& obj)
{
	*this = obj;
}

Bureaucraft& Bureaucraft::operator= (const Bureaucraft& obj)
{
	if (this == &obj)
		return *this;
	_grade = obj._grade;
	return *this;
}

Bureaucraft::~Bureaucraft() {}
