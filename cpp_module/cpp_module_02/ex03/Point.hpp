#ifndef POINT_HPP
 #define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point {
	private:
		const Fixed	x;
		const Fixed	y;
		Point&	operator=(const Point& ref);
	public:
		Point();
		Point(const float& x, const float& y);
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& ref);
		~Point();

		const Fixed&	get_x() const;
		const Fixed&	get_y() const;
};

Fixed	crossVec( Point const a, Point const b);
bool	bsp( Point const a, Point const b, Point const c, Point const point );


#endif
