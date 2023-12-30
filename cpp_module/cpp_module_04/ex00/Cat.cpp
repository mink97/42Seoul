#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "\x1b[33m""[Cat]: default constructor has called!""\x1b[0m" << std::endl;
}

Cat::Cat(Cat const &ref) : Animal() {
	type = ref.type;
	std::cout << "\x1b[35m""[Cat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Cat::~Cat() {
	std::cout << "\x1b[31m""[Cat]: destructor has called!""\x1b[0m" << std::endl;
}

Cat&	Cat::operator=(Cat const &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[Cat]: assign operator has called!""\x1b[0m" << std::endl;
		type = ref.type;
	}
	else
		std::cout << "\x1b[34m""[Cat]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meow! Meow! Meow! Purr... Meow! Meow! Purrrr... Meow! Meow!" << std::endl;
}
