#include "Bureaucrat.hpp"

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
			throw _grade;
	}
	catch (int _grade) {
		std::cout
		<< "Exception: " << _name << " has a grade " << _grade
		<< ". It's too high to decrease!"
		<< std::endl;
	}
}

void	Bureaucraft::decreaseGrade()
{
	try {
		if (_grade + 1 > MIN_GRADE)
			throw _grade;
	}
	catch (int _grade) {
		std::cout
		<< "Exception: " << _name << " has a grade " << _grade
		<< ". It's too low to decrease!"
		<< std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucraft& obj)
{
	out << obj.getName() << ", bureacraft grade " << obj.getGrade();
	return out;
}

Bureaucraft::Bureaucraft(const std::string& name)
	: _name{name}
	, _grade{1}
{}

// Orthodox Canonical Form

Bureaucraft::Bureaucraft()
	: _name{"nameless"}
	, _grade{0}
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
