#include "Form.hpp"

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

void		Form::signForm()
{
	_signed = true;
}

void		Form::beSigned(const Bureaucraft& obj)
{
	try {
		if (obj.getGrade() > getSignGrade())
			throw GradeTooLowException();
		signForm();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

itn	checkGrade(int grade)
{

}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: _name{name}
	, _signed{false}
	, _signGrade{checkGrade(signGrade)}
	, _execGrade{checkGrade(execGrade)}
{
	try {
		if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
			throw GradeTooLowException();
		if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
			throw GradeTooHighException();
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
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

