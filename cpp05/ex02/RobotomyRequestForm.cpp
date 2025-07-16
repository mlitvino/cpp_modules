#include "RobotomyRequestForm.hpp"

void	RobotomyRequestForm::executeForm() const
{
	std::cout << "* some drilling noises *" << std::endl;
	if ((std::clock() % 2) == 0)
	{
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout
		<< "Whoops! The robotomy failed. " << getTarget() << " is a tunecan now"
		<< std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("robotomy request", target, ROBOT_FORM_SIGN, ROBOT_FORM_EXEC)
{}

// Orthodox Canonical

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("nameless", "nameless", ROBOT_FORM_SIGN, ROBOT_FORM_EXEC)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: RobotomyRequestForm()
{
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	return *this;
}
