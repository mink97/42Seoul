#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
	public:
	HumanB( std::string name );
	void	attack( void );
	void	setWeapon( Weapon& weapon );

	private:
	const std::string	name;
	Weapon				*weapon;
};

#endif
