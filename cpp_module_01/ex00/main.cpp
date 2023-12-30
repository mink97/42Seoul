#include "Zombie.hpp"

int	main() {
	Zombie*	zombie1 = newZombie("mingkang");

	zombie1->announce();
	randomChump("ming");
	delete zombie1;
}
