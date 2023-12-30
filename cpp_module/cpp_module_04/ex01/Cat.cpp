#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	brain = new Brain("Cat");
	std::cout << "\x1b[33m""[Cat]: default constructor has called!""\x1b[0m" << std::endl;
}

Cat::Cat(Cat const &ref) : Animal() {
	type = ref.type;
	brain = new Brain;
	for (int i = 0; i < 100; i++)
		brain[i] = ref.brain[i];
	std::cout << "\x1b[35m""[Cat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "\x1b[31m""[Cat]: destructor has called!""\x1b[0m" << std::endl;
}

Cat&	Cat::operator=(Cat const &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[Cat]: assign operator has called!""\x1b[0m" << std::endl;
		type = ref.type;
		for (int i = 0; i < 100; i++)
			brain[i] = ref.brain[i];
	}
	else
		std::cout << "\x1b[34m""[Cat]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meow! Meow! Meow! Purr... Meow! Meow! Purrrr... Meow! Meow!" << std::endl;
}

void Cat::showIdea(int i) {
	if (i < 0 || i >= 100) {
		std::cout << "out of index" << std::endl;
		return ;
	}
	std::cout << "index : " << i << ", idea : " << brain->getIdea(i) << std::endl;
}
