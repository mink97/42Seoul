#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "\x1b[33m""[WrongCat]: default constructor has called!""\x1b[0m" << std::endl;
}

WrongCat::WrongCat(WrongCat const &ref) {
	type = ref.type;
	std::cout << "\x1b[35m""[WrongCat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "\x1b[31m""[WrongCat]: destructor has called!""\x1b[0m" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[WrongCat]: assign operator has called!""\x1b[0m" << std::endl;
		type = ref.type;
	}
	else
		std::cout << "\x1b[34m""[WrongCat]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Meow! Meow! Meow! Purr... Meow! Meow! Purrrr... Meow! Meow!" << std::endl;
}
