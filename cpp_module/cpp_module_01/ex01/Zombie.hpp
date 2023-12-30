#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	name;
public:
	Zombie( std::string name = "amuge" );
	~Zombie( void );
	void	announce( void );
	void	set_name( std::string name );
};

Zombie*	zombieHorde( int N, std::string name );

#endif
