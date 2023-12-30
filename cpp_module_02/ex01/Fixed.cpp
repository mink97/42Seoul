#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	numberValue = 0;
}

Fixed::Fixed( const int val ) {
	if (val > INT_MAX / (1 << fracbits) || val < INT_MIN / (1 << fracbits)) {
		std::cout << "error: The value exceeds the range of fixed-point representation." << std::endl;
		exit(1);
	}
	std::cout << "Int constructor called" << std::endl;
	numberValue = val * (1 << fracbits);
}

Fixed::Fixed( const float val ) {
	if (val > (float)INT_MAX / (1 << fracbits) || (float)val < INT_MIN / (1 << fracbits)) {
		std::cout << "error: The value exceeds the range of fixed-point representation." << std::endl;
		exit(1);
	}
	std::cout << "Float constructor called" << std::endl;
	numberValue = (int)roundf(val * (1 << fracbits));
}

Fixed::Fixed( const Fixed& ref ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed& ref ) {
	std::cout << "Copy assignment operator called" << std::endl;
	numberValue = ref.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (numberValue);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	numberValue = raw;
}

float	Fixed::toFloat( void ) const {
	float	ret;

	ret = (float)numberValue / (1 << fracbits);
	return (ret);
}

int	Fixed::toInt( void ) const {
	int	ret;

	ret = numberValue >> fracbits;
	return (ret);
}

std::ostream&	operator<<( std::ostream& os, const Fixed& fixed ) {
	os << fixed.toFloat();
	return (os);
}
