#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	numberValue = 0;
}

Fixed::Fixed( const Fixed& ref ) {
	std::cout << "Copy constructor called" << std::endl;
	this->numberValue = ref.getRawBits();
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
