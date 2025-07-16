#include "AForm.hpp"

void	AForm::beSigned(int grade)
{
	if (grade > getSignGrade())
		throw GradeTooLowException();
	_signed = true;
}

std::ostream&	operator<<(std::ostream& out, const AForm& obj)
{
	out
	<< obj.getName() << ", AForm grade to sign " << obj.getSignGrade()
	<< ", grade to execute " << obj.getExecGrade()
	<< ", signed " << (obj.isSigned() ? " true" : " false")
	<< ", target " << obj.getTarget();
	return out;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (isSigned() == false)
		throw IsNotSigendException();
	else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	executeForm();
}

// Getters

bool AForm::isSigned() const
{
	return _signed;
}

const std::string& AForm::getName() const
{
	return _name;
}

const int&	AForm::getSignGrade() const
{
	return _signGrade;
}

const int&	AForm::getExecGrade() const
{
	return _execGrade;
}

const std::string& AForm::getTarget() const
{
	return _target;
}

// Extra Constructors

AForm::AForm(const std::string& name, const std::string& target, int signGrade, int execGrade)
	: _name{name}
	, _signed{false}
	, _signGrade{signGrade}
	, _execGrade{execGrade}
	, _target{target}
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
	else if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
}

// Orthodox Canonical

AForm::AForm()
	: _name{"nameless"}
	, _signed{false}
	, _signGrade{75}
	, _execGrade{75}
{}

AForm::~AForm() {}

AForm::AForm(const AForm& obj)
	: AForm()
{
	*this = obj;
}

AForm& AForm::operator= (const AForm& obj)
{
	if (this == &obj)
		return *this;
	_signed = obj._signed;
	return *this;
}

