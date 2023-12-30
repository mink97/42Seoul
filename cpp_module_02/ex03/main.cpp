#include "Point.hpp"

int main( void ) {
	Point	a(4, 8);
	Point	b(8, 10);
	Point	c(7, 5);
	Point	point(6, 8);

	std::cout << std::boolalpha << bsp(a, b, c, point) << std::endl;
	return 0;
}
