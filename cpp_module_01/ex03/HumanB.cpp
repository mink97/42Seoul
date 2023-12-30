#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name) {
	weapon = NULL;
	std::cout << "name : " << name << std::endl;
}

void	HumanB::attack( void ) {
	if (weapon == NULL)
		std::cout << name << " attacks with their bare hands" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon ) {
	this->weapon = &weapon;
}
