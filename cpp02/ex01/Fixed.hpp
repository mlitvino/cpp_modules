#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_nbr;
		static const int _fract = 8;
	public:
		Fixed(void);
		~Fixed();
		explicit	Fixed(const int nbr);
		explicit	Fixed(const Fixed& fixed);
		Fixed&		operator= (const Fixed &fixed);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

#endif
