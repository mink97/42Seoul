#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float& x, const float& y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y) {}

Point::Point(const Point& ref) : x(ref.x), y(ref.y) {}

Point::~Point() {}

Point&	Point::operator=(const Point& ref)
{
	(void)ref;
	return (*this);
}

const Fixed&	Point::get_x() const
{
	return (x);
}

const Fixed&	Point::get_y() const
{
	return (y);
}
