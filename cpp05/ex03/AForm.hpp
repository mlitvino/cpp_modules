#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		const std::string	_target;
	protected:
		virtual void	executeForm() const = 0;
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm& obj);
		AForm& operator= (const AForm& obj);

		AForm(const std::string& name, const std::string& target, int signGrade, int execGrade);

		const std::string& getName() const;
		const int&	getSignGrade() const;
		const int&	getExecGrade() const;
		const std::string& getTarget() const;

		void			execute(Bureaucrat const & executor) const;
		bool			isSigned() const;
		void			beSigned(int grade);

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
	class IsNotSigendException : public std::exception
	{
		public:
			const char* what() const noexcept override
			{
				return "The form is not signed!";
			}
	};
};

std::ostream&	operator<<(std::ostream& out, const AForm& obj);

#endif
