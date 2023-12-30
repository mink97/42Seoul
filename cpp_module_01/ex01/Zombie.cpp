#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name) {
	std::cout << "A zombie has appeard!!" << std::endl;
}

void	Zombie::set_name( std::string name ) {
	this->name = name;
}

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << name << " zombie has been eliminated" << std::endl;
}
