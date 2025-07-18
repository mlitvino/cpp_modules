#include "Bureaucrat.hpp"

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int		Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::increaseGrade()
{
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooLowException();
	--_grade;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooHighException();
	++_grade;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureacraft grade " << obj.getGrade();
	return out;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name{name}
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

// Orthodox Canonical Form

Bureaucrat::Bureaucrat()
	: _name{"nameless"}
	, _grade{75}
{}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	*this = obj;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& obj)
{
	if (this == &obj)
		return *this;
	_grade = obj._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}
