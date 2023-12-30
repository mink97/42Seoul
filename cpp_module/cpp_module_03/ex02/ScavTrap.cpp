#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
	ClapTrap("default name", 100, 50, 20)
{
	std::cout << "default ScavTrap constructor has been called!!" << std::endl;
}

ScavTrap::ScavTrap(std::string name, unsigned int hp,
		unsigned int energy, unsigned int damage) :
	ClapTrap(name, hp, energy, damage)
{
	std::cout << name << " ScavTrap constructor has been called!!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) :
	ClapTrap(ref.get_name(), ref.get_hitPoints(), ref.get_energyPoints(), ref.get_attackDamage())
{
	std::cout << "copied ScavTrap constructor has been called!!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor has been called!!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	ClapTrap::operator=(ref);
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (get_hitPoints() <= 0) {
		std::cout << "ScavTrap \033[0;93m" << get_name() << "\033[0;39m has already died. ";
		std::cout << "ScavTrap \033[0;93m" << get_name() << "\033[0;39m can't attack " << target << "." << std::endl;
		return ;
	} else if (get_energyPoints() <= 0) {
		std::cout << "ScavTrap \033[0;93m" << get_name() << "\033[0;39m has no energy. ";
		std::cout << "ScavTrap \033[0;93m" << get_name() << "\033[0;39m can't attack " << target << "." << std::endl;
		return ;
	}
	std::cout << "\033[0;93mScavTrap " << get_name() << "\033[0;39m attacks " << target
	<< ", causing " << get_attackDamage() << " points of damage!" << std::endl;
	set_energyPoints(get_energyPoints() - 1);
}

void	ScavTrap::guardGate()
{
	std::cout << "\033[0;93m" << get_name() << "\033[0;39m ScavTrap is now in Gate keeper mode." << std::endl;
}
