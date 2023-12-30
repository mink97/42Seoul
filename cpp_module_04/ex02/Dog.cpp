#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	brain = new Brain("Dog");
	std::cout << "\x1b[33m""[Dog]: default constructor has called!""\x1b[0m" << std::endl;
}

Dog::Dog(Dog const &ref) : Animal() {
	this->type = ref.type;
	brain = new Brain;
	for (int i = 0; i < 100; i++)
		brain[i] = ref.brain[i];
	std::cout << "\x1b[35m""[Dog]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "\x1b[31m""[Dog]: destructor has called!""\x1b[0m" << std::endl;
}

Dog&	Dog::operator=(Dog const &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[Dog]: assign operator has called!""\x1b[0m" << std::endl;
		type = ref.type;
		for (int i = 0; i < 100; i++)
			brain[i] = ref.brain[i];
	}
	else
		std::cout << "\x1b[34m""[Dog]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Ruff! Ruff! Ruff! Woof-woof! Bark! Bark! Bark! Arf-arf! Bow-wow!" << std::endl;
}
