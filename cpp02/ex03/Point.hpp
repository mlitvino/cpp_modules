#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const Fixed& x, const Fixed& y);
		~Point();
		Point(const Point& point);
		Point& operator= (const Point& point);
		float getX() const;
		float getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
float	sign(const Point& p1, const Point& p2, const Point& p3);

#endif
