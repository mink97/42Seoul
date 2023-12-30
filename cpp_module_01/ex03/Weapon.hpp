#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	public:
	Weapon( std::string type = "bare hands" );
	// ~Weapon();
	std::string	getType( void );
	void		setType( std::string type );

	private:
	std::string	type;
};

#endif
