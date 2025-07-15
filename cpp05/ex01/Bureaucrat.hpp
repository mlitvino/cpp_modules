#ifndef BUREAUCRAFT_HPP
#define BUREAUCRAFT_HPP

#include <string>
#include <iostream>

#include "Form.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucraft
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucraft();
		~Bureaucraft();
		Bureaucraft(const Bureaucraft& obj);
		Bureaucraft& operator= (const Bureaucraft& obj);

		Bureaucraft(const std::string& name);
		Bureaucraft(const std::string& name, int grade);
		const std::string&	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(Form& obj) const;

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Grade too low!";
			}
	};
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Grade too high!";
			}
	};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucraft& obj);

#endif
