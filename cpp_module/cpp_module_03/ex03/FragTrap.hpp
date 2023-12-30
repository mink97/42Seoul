#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:

	public:
		FragTrap();
		FragTrap(std::string name, unsigned int hp = 100,
				unsigned int energy = 100, unsigned int damage = 30);
		FragTrap(const FragTrap& ref);
		virtual ~FragTrap();

		FragTrap&	operator=(const FragTrap& ref);

		void	highFivesGuys();
};

#endif
