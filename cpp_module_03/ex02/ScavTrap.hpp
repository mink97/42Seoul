#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		ScavTrap();

	public:
		ScavTrap(std::string name, unsigned int hp = 100,
				unsigned int energy = 50, unsigned int damage = 20);
		ScavTrap(const ScavTrap& ref);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& ref);

		void	attack(const std::string& target);
		void	guardGate();
};

#endif
