#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "\x1b[33m""[Dog]: default constructor has called!""\x1b[0m" << std::endl;
}

Dog::Dog(Dog const &ref) : Animal() {
	this->type = ref.type;
	std::cout << "\x1b[35m""[Dog]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Dog::~Dog() {
	std::cout << "\x1b[31m""[Dog]: destructor has called!""\x1b[0m" << std::endl;
}

Dog&	Dog::operator=(Dog const &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[Dog]: assign operator has called!""\x1b[0m" << std::endl;
		type = ref.type;
	}
	else
		std::cout << "\x1b[34m""[Dog]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Ruff! Ruff! Ruff! Woof-woof! Bark! Bark! Bark! Arf-arf! Bow-wow!" << std::endl;
}
