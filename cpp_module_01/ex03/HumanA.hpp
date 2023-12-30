#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
	HumanA( std::string name, Weapon& weapon );
	void	attack( void );

	private:
	const std::string	name;
	Weapon				&weapon;
};

#endif
