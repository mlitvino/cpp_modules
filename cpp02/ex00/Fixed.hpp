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
		Fixed(const Fixed& obj);
		Fixed&		operator= (const Fixed &obj);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

#endif
