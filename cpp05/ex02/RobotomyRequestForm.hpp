#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <ctime>

#define ROBOT_FORM_SIGN 72
#define ROBOT_FORM_EXEC 45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator= (const RobotomyRequestForm& obj);

		RobotomyRequestForm(const std::string& target);
		void	executeForm() const override;
};

#endif
