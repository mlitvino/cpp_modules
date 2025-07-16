#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;
#include "Form.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator= (const Bureaucrat& obj);

		Bureaucrat(const std::string& name, int grade);
		const std::string&	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(Form& obj);

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const noexcept override
			{
				return "Grade too low!";
			}
	};
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const noexcept override
			{
				return "Grade too high!";
			}
	};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
