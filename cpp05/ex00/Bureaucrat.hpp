#ifndef BUREAUCRAFT_HPP
#define BUREAUCRAFT_HPP

#include <string>
#include <iostream>

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
		const std::string&	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
};

std::ostream&	operator<<(std::ostream& out, const Bureaucraft& obj);

#endif
