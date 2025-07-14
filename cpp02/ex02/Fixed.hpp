#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <cfloat>

class Fixed
{
	private:
		int	_nbr;
		static const int _fract = 8;
	public:
		Fixed(void);
		~Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& obj);
		Fixed&		operator= (const Fixed &obj);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
		static const Fixed&	max(const Fixed &obj1, const Fixed &obj2);
		static Fixed&	max(Fixed &obj1, Fixed &obj2);
		static const Fixed&	min(const Fixed &obj1, const Fixed &obj2);
		static Fixed&	min(Fixed &obj1, Fixed &obj2);
		bool		operator> (const Fixed &obj) const;
		bool		operator< (const Fixed &obj) const;
		bool		operator>= (const Fixed &obj) const;
		bool		operator<= (const Fixed &obj) const;
		bool		operator== (const Fixed &obj) const;
		bool		operator!= (const Fixed &obj) const;
		Fixed		operator+ (const Fixed &obj);
		Fixed		operator- (const Fixed &obj);
		Fixed		operator* (const Fixed &obj);
		Fixed		operator/ (const Fixed &obj);
		Fixed&		operator++ ();
		Fixed		operator++ (int);
		Fixed&		operator-- ();
		Fixed		operator-- (int);
};

std::ostream&	operator<< (std::ostream& cout, const Fixed& obj);

#endif
