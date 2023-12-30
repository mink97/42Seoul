#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << name << " ClapTrap constructor has been called!!" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp,
		unsigned int energy, unsigned int damage) :
	name(name), hitPoints(hp), energyPoints(energy), attackDamage(damage)
{
	std::cout << name << " ClapTrap constructor has been called!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) :
	name(ref.name), hitPoints(ref.hitPoints),
	energyPoints(ref.energyPoints), attackDamage(ref.attackDamage)
{
	std::cout << "copied ClapTrap constructor has been called!!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " ClapTrap destructor has been called!!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	return (*this);
}

void	ClapTrap::set_hitPoints(unsigned int n)
{
	hitPoints = n;
}

void	ClapTrap::set_energyPoints(unsigned int n)
{
	energyPoints = n;
}

void	ClapTrap::set_attackDamage(unsigned int n)
{
	attackDamage = n;
}

void	ClapTrap::set_name(std::string str)
{
	name = str;
}


std::string	ClapTrap::get_name() const
{
	return (name);
}

unsigned int	ClapTrap::get_hitPoints() const
{
	return (hitPoints);
}

unsigned int	ClapTrap::get_energyPoints() const
{
	return (energyPoints);
}

unsigned int	ClapTrap::get_attackDamage() const
{
	return (attackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0) {
		std::cout << "ClapTrap \033[0;93m" << name << "\033[0;39m has already died. ";
		std::cout << "ClapTrap \033[0;93m" << name << "\033[0;39m can't attack " << target << "." << std::endl;
		return ;
	} else if (energyPoints <= 0) {
		std::cout << "ClapTrap \033[0;93m" << name << "\033[0;39m has no energy. ";
		std::cout << "ClapTrap \033[0;93m" << name << "\033[0;39m can't attack " << target << "." << std::endl;
		return ;
	}
	std::cout << "ClapTrap \033[0;93m" << name << "\033[0;39m attacks " << target
	<< ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\033[0;93m" << name << "\033[0;39m has been attacked." << std::endl;
	std::cout << "\033[0;93m" << name << "\033[0;39m has taken " << amount << " damage!!" << std::endl;
	if (hitPoints <= amount) {
		hitPoints = 0;
		std::cout << "\033[0;93m" << name << "\033[0;39m has died." << std::endl;
	}
	else {
		hitPoints -= amount;
		std::cout << "\033[0;93m" << name << "\033[0;39m's HP is " << hitPoints << "." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0) {
		std::cout << "\033[0;93m" << name << "\033[0;39m has already died. ";
		std::cout << "\033[0;93m" << name << "\033[0;39m can't be repaired." << std::endl;
		return ;
	} else if (energyPoints <= 0) {
		std::cout << "\033[0;93m" << name << "\033[0;39m has no energy. ";
		std::cout << "\033[0;93m" << name << "\033[0;39m can't be repaired." << std::endl;
		return ;
	}
	if (amount > 10000 || hitPoints + amount > 10000)
		hitPoints = 10000;
	else
		hitPoints += amount;
	std::cout << "\033[0;93m" << name << "\033[0;39m has been repaired." << std::endl;
	energyPoints--;
	std::cout << "\033[0;93m" << name << "\033[0;39m's HP is " << hitPoints << "." << std::endl;
}
