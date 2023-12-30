#include "Character.hpp"

Character::Character() : name("empty") {
	std::cout << "\x1b[33m""[Character]: default constructor has called!""\x1b[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const& name) : name(name) {
	std::cout << "\x1b[33m""[Character]: " << name << " constructor has called!""\x1b[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(Character const &ref) : name(ref.name) {
	std::cout << "\x1b[35m""[Character]: deep-copy constructor has called!""\x1b[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (ref.inventory[i]) {
			inventory[i] = ref.inventory[i]->clone();
		}
		else
			inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (inventory[i]) {
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	std::cout << "\x1b[31m""[Character]: destructor has called!""\x1b[0m" << std::endl;
}

Character&	Character::operator=(Character const &ref) {
	if (this != &ref) {
		std::cout << "\x1b[34m""[Character]: assign operator has called!""\x1b[0m" << std::endl;
		name = ref.name;
		for (int i = 0; i < 4; i++) {
			if (inventory[i])
				delete inventory[i];
			if (ref.inventory[i]) {
				inventory[i] = ref.inventory[i]->clone();
			}
			else
				inventory[i] = NULL;
		}
	}
	else
		std::cout << "\x1b[34m""[Character]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

std::string const & Character::getName() const {
	return (name);
}

void Character::equip(AMateria* m) {
	int i = 0;
	for (; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			break;
		}
	}
	if (i == 4)
		delete m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		inventory[idx]->use(target);
	}
}

AMateria* Character::getAddress(int idx) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		return (inventory[idx]);
	}
	return (0);
}
