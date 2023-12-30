#include "Zombie.hpp"

Zombie::Zombie( std::string name) : name(name) {
	std::cout << name << " zombie has appeard!!" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << name << " zombie has been eliminated" << std::endl;
}
