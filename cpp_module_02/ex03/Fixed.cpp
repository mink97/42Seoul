#include "Fixed.hpp"

Fixed::Fixed() {
	numberValue = 0;
}

Fixed::Fixed( const int val ) {
	if (val > INT_MAX / (1 << fracbits) || val < INT_MIN / (1 << fracbits)) {
		std::cout << "error: The value exceeds the range of fixed-point representation." << std::endl;
		exit(1);
	}
	numberValue = val * (1 << fracbits);
}

Fixed::Fixed( const float val ) {
	if (val > (float)INT_MAX / (1 << fracbits) || (float)val < INT_MIN / (1 << fracbits)) {
		std::cout << "error: The value exceeds the range of fixed-point representation." << std::endl;
		exit(1);
	}
	numberValue = (int)roundf(val * (1 << fracbits));
}

Fixed::Fixed( const Fixed& ref ) {
	*this = ref;
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=( const Fixed& ref ) {
	numberValue = ref.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	return (numberValue);
}

void	Fixed::setRawBits( int const raw ) {
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

bool	Fixed::operator>( const Fixed& ref ) {
	return this->toFloat() > ref.toFloat();
}
bool	Fixed::operator<( const Fixed& ref ) {
	return this->toFloat() < ref.toFloat();
}
bool	Fixed::operator>=( const Fixed& ref ) {
	return this->toFloat() >= ref.toFloat();
}
bool	Fixed::operator<=( const Fixed& ref ) {
	return this->toFloat() <= ref.toFloat();
}
bool	Fixed::operator==( const Fixed& ref ) {
	return this->toFloat() == ref.toFloat();
}
bool	Fixed::operator!=( const Fixed& ref ) {
	return this->toFloat() != ref.toFloat();
}

const Fixed	Fixed::operator*( const Fixed& ref) const {
	Fixed	ret;

	ret.setRawBits((this->numberValue * ref.numberValue) / (1 << fracbits));
	return (ret);
}
const Fixed	Fixed::operator/( const Fixed& ref) const {
	Fixed	ret;

	ret.setRawBits((this->numberValue / ref.numberValue) * (1 << fracbits));
	return (ret);
}
const Fixed	Fixed::operator+( const Fixed& ref) const {
	Fixed	ret;

	ret.setRawBits(this->numberValue + ref.numberValue);
	return (ret);
}
const Fixed	Fixed::operator-( const Fixed& ref) const {
	Fixed	ret;

	ret.setRawBits(this->numberValue - ref.numberValue);
	return (ret);
}

Fixed&	Fixed::operator++() {
	this->numberValue++;
	return (*this);
}
Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	this->numberValue++;
	return temp;
}
Fixed&	Fixed::operator--() {
	this->numberValue--;
	return (*this);
}
Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	this->numberValue--;
	return temp;
}

Fixed&	Fixed::min( Fixed& refA, Fixed& refB ) {
	if (refA.numberValue > refB.numberValue) return refB;
	return refA;
}
const Fixed&	Fixed::min( const Fixed& refA, const Fixed& refB ) {
	if (refA.numberValue > refB.numberValue) return refB;
	return refA;
}
Fixed&	Fixed::max( Fixed& refA, Fixed& refB ) {
	if (refA.numberValue > refB.numberValue) return refA;
	return refB;
}
const Fixed&	Fixed::max( const Fixed& refA, const Fixed& refB ) {
	if (refA.numberValue > refB.numberValue) return refA;
	return refB;
}
