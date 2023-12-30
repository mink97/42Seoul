#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	name;

	public:
		DiamondTrap();
		// DiamondTrap(std::string name);
		DiamondTrap(std::string name, unsigned int hp = 100,
				unsigned int energy = 50, unsigned int damage = 30);
		DiamondTrap(const DiamondTrap& ref);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap& ref);

		std::string		get_name() const;
		void	set_name(std::string str);
		void	whoAmI();
};

#endif
