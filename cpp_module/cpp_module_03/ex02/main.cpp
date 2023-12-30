#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	FragTrap	s1("one");
	FragTrap	s2("two");
	FragTrap	s3("three");
	FragTrap	s4("four");

	std::cout << "\n\033[0;94m--------------------------FragTrap attack--------------------------\033[0;39m" << std::endl;
	s1.attack("two");
	s2.takeDamage(s1.get_attackDamage());
	std::cout << "\n\033[0;94m--------------------------FragTrap repair--------------------------\033[0;39m" << std::endl;
	s3.beRepaired(5);
	std::cout << "\n\033[0;94m--------------------test when FragTrap's HP is 0-------------------\033[0;39m" << std::endl;
	s4.takeDamage(150);
	s4.attack("one");
	s4.beRepaired(3);
	s4.highFivesGuys();
	std::cout << "\n\033[0;94m------------------test when FragTrap's energy is 0-----------------\033[0;39m" << std::endl;
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
