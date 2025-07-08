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
		Fixed(const float f);
		Fixed(const Fixed& fixed);
		Fixed&		operator= (const Fixed &fixed);
		friend std::ostream&	operator<< (std::ostream& cout, const Fixed& fixed);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
		static const Fixed&	max(const Fixed &nbr1, const Fixed &nbr2);
		static Fixed&	max(Fixed &nbr1, Fixed &nbr2);
		static const Fixed&	min(const Fixed &nbr1, const Fixed &nbr2);
		static Fixed&	min(Fixed &nbr1, Fixed &nbr2);
		bool		operator> (const Fixed &nbr) const;
		bool		operator< (const Fixed &nbr) const;
		bool		operator>= (const Fixed &nbr) const;
		bool		operator<= (const Fixed &nbr) const;
		bool		operator== (const Fixed &nbr) const;
		bool		operator!= (const Fixed &nbr) const;
		Fixed		operator+ (const Fixed &fixed);
		Fixed		operator- (const Fixed &fixed);
		Fixed		operator* (const Fixed &fixed);
		Fixed		operator/ (const Fixed &fixed);
		Fixed&		operator++ ();
		Fixed		operator++ (int);
		Fixed&		operator-- ();
		Fixed		operator-- (int);
};

#endif
