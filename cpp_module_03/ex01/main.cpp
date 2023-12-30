#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ScavTrap	s1("one");
	ScavTrap	s2("two");
	ScavTrap	s3("three");
	ScavTrap	s4("four");

	std::cout << "\n\033[0;94m--------------------------ScavTrap attack--------------------------\033[0;39m" << std::endl;
	s1.attack("two");
	s2.takeDamage(s1.get_attackDamage());
	std::cout << "\n\033[0;94m--------------------------ScavTrap repair--------------------------\033[0;39m" << std::endl;
	s3.beRepaired(5);
	std::cout << "\n\033[0;94m--------------------test when ScavTrap's HP is 0-------------------\033[0;39m" << std::endl;
	s4.takeDamage(150);
	s4.attack("one");
	s4.beRepaired(3);
	s4.guardGate();
	std::cout << "\n\033[0;94m------------------test when ScavTrap's energy is 0-----------------\033[0;39m" << std::endl;
	std::cout << "c3's energy : " << s3.get_energyPoints() << std::endl;
	s3.beRepaired(5);
	std::cout << "c3's energy : " << s3.get_energyPoints() << std::endl;
	s3.beRepaired(5);
	std::cout << "c3's energy : " << s3.get_energyPoints() << std::endl;
	s3.beRepaired(5);
	std::cout << "c3's energy : " << s3.get_energyPoints() << std::endl;
	s3.beRepaired(5);
	std::cout << "c3's energy : " << s3.get_energyPoints() << std::endl;
}
