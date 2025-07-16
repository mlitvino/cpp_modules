#include "Form.hpp"

void	Form::beSigned(int grade)
{
	if (grade > getSignGrade())
		throw GradeTooLowException();
	_signed = true;
}

std::ostream&	operator<<(std::ostream& out, const Form& obj)
{
	out
	<< obj.getName() << ", form grade to sign " << obj.getSignGrade()
	<< ", grade to execute " << obj.getExecGrade()
	<< ", signed " << obj.isSigned() ? " true" : " false";
	return out;
}

// Getters

bool Form::isSigned() const
{
	return _signed;
}

const std::string& Form::getName() const
{
	return _name;
}

const int&	Form::getSignGrade() const
{
	return _signGrade;
}

const int&	Form::getExecGrade() const
{
	return _execGrade;
}

// Extra Constructors

Form::Form(const std::string& name, int signGrade, int execGrade)
	: _name{name}
	, _signed{false}
	, _signGrade{signGrade}
	, _execGrade{execGrade}
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
}

// Orthodox Canonical Form

Form::Form()
	: _name{"nameless"}
	, _signed{false}
	, _signGrade{75}
	, _execGrade{75}
{}

Form::~Form() {}

Form::Form(const Form& obj)
	: Form()
{
	*this = obj;
}

Form& Form::operator= (const Form& obj)
{
	if (this == &obj)
		return *this;
	_signed = obj._signed;
	return *this;
}

