#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		Form();
		~Form();
		Form(const Form& obj);
		Form& operator= (const Form& obj);

		Form(const std::string& name, int signGrade, int execGrade);

		const std::string& getName() const;
		const int&	getSignGrade() const;
		const int&	getExecGrade() const;

		bool		isSigned() const;
		void		beSigned(int grade);

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

std::ostream&	operator<<(std::ostream& out, const Form& obj);

#endif
