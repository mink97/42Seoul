#include "FragTrap.hpp"

FragTrap::FragTrap() :
	ClapTrap("default name", 100, 100, 30)
{
	std::cout << "default FragTrap constructor has been called!!" << std::endl;
}

FragTrap::FragTrap(std::string name, unsigned int hp,
		unsigned int energy, unsigned int damage) :
	ClapTrap(name, hp, energy, damage)
{
	std::cout << name << " FragTrap constructor has been called!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) :
	ClapTrap(ref.get_name(), ref.get_hitPoints(), ref.get_energyPoints(), ref.get_attackDamage())
{
	std::cout << "copied FragTrap constructor has been called!!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor has been called!!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& ref)
{
	ClapTrap::operator=(ref);
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "high fives guys!!" << std::endl;
}
