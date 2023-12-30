#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "\x1b[33m""[WrongAnimal]: default constructor has called!""\x1b[0m" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref) {
	std::cout << "\x1b[35m""[WrongAnimal]: deep-copy constructor has called!""\x1b[0m" << std::endl;
	type = ref.type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "\x1b[31m""[WrongAnimal]: destructor has called!""\x1b[0m" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[WrongAnimal]: assign operator has called!""\x1b[0m" << std::endl;
		type = ref.type;
	}
	else
		std::cout << "\x1b[34m""[WrongAnimal]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "<Unknown animal sound>" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}
