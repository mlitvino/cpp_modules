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
		Fixed(const int nbr);
		Fixed(const float f);
		Fixed(const Fixed& obj);
		Fixed&		operator= (const Fixed &obj);
		friend std::ostream&	operator<< (std::ostream& cout, const Fixed& obj);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
};

#endif
