#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int					numberValue;
	static const int	fracbits = 8;

public:
	Fixed();
	Fixed( const int val );
	Fixed( const float val );
	Fixed( const Fixed& ref );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed&	operator=( const Fixed& ref );

	static Fixed&	min( Fixed& refA, Fixed& refB );
	static const Fixed&	min( const Fixed& refA, const Fixed& refB );
	static Fixed&	max( Fixed& refA, Fixed& refB );
	static const Fixed&	max( const Fixed& refA, const Fixed& refB );

	// comparison operators
	bool	operator>( const Fixed& ref );
	bool	operator<( const Fixed& ref );
	bool	operator>=( const Fixed& ref );
	bool	operator<=( const Fixed& ref );
	bool	operator==( const Fixed& ref );
	bool	operator!=( const Fixed& ref );

	// arithmetic operators
	const Fixed	operator*( const Fixed& ref) const;
	const Fixed	operator/( const Fixed& ref) const;
	const Fixed	operator+( const Fixed& ref) const;
	const Fixed	operator-( const Fixed& ref) const;

	// increment/decrement operators
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
};

std::ostream&	operator<<( std::ostream& os, const Fixed& fixed );

#endif
