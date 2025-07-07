#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_nbr;
		static const int _fract = 8;
	public:
		Fixed(void);
		~Fixed();
		explicit	Fixed(const int nbr);
		explicit	Fixed(const float f);
		explicit	Fixed(const Fixed& fixed);
		Fixed&		operator= (const Fixed &fixed);
		friend std::ostream&	operator<< (std::ostream& cout, const Fixed& fixed);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
};

#endif
