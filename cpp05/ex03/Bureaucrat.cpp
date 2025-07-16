#include "Bureaucrat.hpp"

void	Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout
		<< "Error: "
		<< _name << " couldn't execute " << form.getName() << " because " << e.what()
		<< std::endl;
	}
}

void	Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(getGrade());
		std::cout << _name << " signed " << obj.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout
		<< _name << " couldn't sign " << obj.getName() << " because " << e.what()
		<< std::endl;
	}
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

// Getters

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int		Bureaucrat::getGrade() const
{
	return _grade;
}

// Extra Constructors

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name{name}
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
	_grade = grade;
}

// Orthodox Canonical

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
