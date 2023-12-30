#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap("default_clap_name"), name("default") // check later
{
	set_hitPoints(100);
	set_energyPoints(50);
	set_attackDamage(30);
	std::cout << "default DiamondTrap constructor has been called!!" << std::endl;
}

// test1
// DiamondTrap::DiamondTrap(std::string name) :
// 	ClapTrap(), ScavTrap(), FragTrap(name + "_clap_name"), name(name)
// {
// 	set_energyPoints(50);
// 	std::cout << name << " DiamondTrap constructor has been called!!" << std::endl;
// }

// // test2
// DiamondTrap::DiamondTrap(std::string name) :
// 	ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
// {
// 	set_energyPoints(50);
// 	std::cout << name << " DiamondTrap constructor has been called!!" << std::endl;
// }

// test3
// DiamondTrap::DiamondTrap(std::string name) :
// 	ClapTrap(name + "_clap_name"), name(name)
// {
// 	set_hitPoints(100);
// 	set_energyPoints(50);
// 	set_attackDamage(30);
// 	std::cout << name << " DiamondTrap constructor has been called!!" << std::endl;
// }

DiamondTrap::DiamondTrap(std::string name, unsigned int hp,
		unsigned int energy, unsigned int damage) :
	ClapTrap(name + "_clap_name", hp, energy, damage), name(name)
{
	std::cout << name << " DiamondTrap constructor has been called!!" << std::endl;
}

// // test
// DiamondTrap::DiamondTrap(std::string name, unsigned int hp,
// 		unsigned int energy, unsigned int damage) :
// 	FragTrap(name + "clap_name", hp, energy, damage), name(name)
// {
// 	std::cout << name << " DiamondTrap constructor has been called!!" << std::endl;
// }

DiamondTrap::DiamondTrap(const DiamondTrap& ref) :
	ClapTrap(ref.ClapTrap::get_name(), ref.get_hitPoints(), ref.get_energyPoints(), ref.get_attackDamage()), name(ref.get_name())
{
	std::cout << "copied DiamondTrap constructor has been called!!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor has been called!!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref)
{
	ClapTrap::operator=(ref);
	set_name(ref.get_name());
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "my ClapTrap name is " << ClapTrap::get_name() << std::endl;
	std::cout << "my real name is " << get_name() << std::endl;
}

void	DiamondTrap::set_name(std::string str)
{
	name = str;
}

std::string	DiamondTrap::get_name() const
{
	return (name);
}
