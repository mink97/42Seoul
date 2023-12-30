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
};

std::ostream&	operator<<( std::ostream& os, const Fixed& fixed );

#endif
