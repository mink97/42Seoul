#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int					numberValue;
	static const int	fracbits = 8;

public:
	Fixed();
	Fixed( const Fixed& ref );
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	Fixed&	operator=( const Fixed& ref );
};

#endif
