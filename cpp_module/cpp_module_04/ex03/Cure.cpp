#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "\x1b[33m""[Cure]: default constructor has called!""\x1b[0m" << std::endl;
}

Cure::Cure(Cure const &ref) : AMateria() {
	(void)ref;
	type = "cure";
	std::cout << "\x1b[35m""[Cure]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Cure::~Cure() {
	std::cout << "\x1b[31m""[Cure]: destructor has called!""\x1b[0m" << std::endl;
}

Cure&	Cure::operator=(Cure const &ref) {
	if (this != &ref) {
		std::cout << "\x1b[34m""[Cure]: assign operator has called!""\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[34m""[Cure]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

AMateria* Cure::clone() const {
	AMateria* ret = new Cure(*this);

	return (ret);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
