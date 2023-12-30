#include "Animal.hpp"

Animal::Animal() {
	std::cout << "\x1b[33m""[Animal]: default constructor has called!""\x1b[0m" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal& ref) {
	std::cout << "\x1b[35m""[Animal]: deep-copy constructor has called!""\x1b[0m" << std::endl;
	type = ref.type;
}

Animal::~Animal() {
	std::cout << "\x1b[31m""[Animal]: destructor has called!""\x1b[0m" << std::endl;
}

Animal&	Animal::operator=(const Animal &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[Animal]: assign operator has called!""\x1b[0m" << std::endl;
		type = ref.type;
	}
	else
		std::cout << "\x1b[34m""[Animal]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "<Unknown animal sound>" << std::endl;
}

std::string Animal::getType() const {
	return (type);
}

void Animal::showIdea(int i) {
	std::cout << "index : " << i << ", idea : empty" << std::endl;
}
