#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
		ClapTrap();

	public:
		ClapTrap(std::string name, unsigned int hp = 10,
				unsigned int energy = 10, unsigned int damage = 0);
		ClapTrap(const ClapTrap& ref);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap& ref);

		std::string		get_name() const;
		unsigned int	get_hitPoints() const;
		unsigned int	get_energyPoints() const;
		unsigned int	get_attackDamage() const;

		void	set_hitPoints(unsigned int n);
		void	set_energyPoints(unsigned int n);
		void	set_attackDamage(unsigned int n);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
