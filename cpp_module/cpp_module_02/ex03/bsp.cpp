#include "Point.hpp"

Fixed	crossVec( Point const a, Point const b) {
	Fixed ret = a.get_x() * b.get_y() - b.get_x() * a.get_y();
	return (ret);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	Point	ap(point.get_x() - a.get_x(), point.get_y() - a.get_y());
	Point	ab(b.get_x() - a.get_x(), b.get_y() - a.get_y());
	Point	bp(point.get_x() - b.get_x(), point.get_y() - b.get_y());
	Point	bc(c.get_x() - b.get_x(), c.get_y() - b.get_y());
	Point	cp(point.get_x() - c.get_x(), point.get_y() - c.get_y());
	Point	ca(a.get_x() - c.get_x(), a.get_y() - c.get_y());

	if ((crossVec(ap, ab) * crossVec(bp, bc)).toFloat() > 0)
		if ((crossVec(ap, ab) * crossVec(cp, ca)).toFloat() > 0)
			return true;
	return false;
}
