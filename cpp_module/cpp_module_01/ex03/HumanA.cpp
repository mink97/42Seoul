#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : name(name), weapon(weapon) {
	std::cout << "name : " << name << std::endl;
	std::cout << "weapon : " << weapon.getType() << std::endl;
}

void	HumanA::attack( void ) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
