#include "ClapTrap.hpp"

int	main() {
	ClapTrap	c1("one");
	ClapTrap	c2("two");
	ClapTrap	c3("three");
	ClapTrap	c4 = c3;

	std::cout << "\n\033[0;94m--------------------------ClapTrap attack--------------------------\033[0;39m" << std::endl;
	c1.attack("two");
	c2.takeDamage(0);
	std::cout << "\n\033[0;94m--------------------------ClapTrap repair--------------------------\033[0;39m" << std::endl;
	c3.beRepaired(5);
	std::cout << "\n\033[0;94m--------------------test when ClapTrap's HP is 0-------------------\033[0;39m" << std::endl;
	c4.takeDamage(15);
	c4.attack("one");
	c4.beRepaired(3);
	std::cout << "\n\033[0;94m------------------test when ClapTrap's energy is 0-----------------\033[0;39m" << std::endl;
	c3.beRepaired(5);
	c3.attack("nothing");
	c3.beRepaired(5);
	c3.attack("nothing");
	c3.beRepaired(5);
	c3.attack("nothing");
	c3.beRepaired(5);
	c3.attack("nothing");
	c3.beRepaired(5);
	c3.attack("nothing");
	c3.beRepaired(5);
}
