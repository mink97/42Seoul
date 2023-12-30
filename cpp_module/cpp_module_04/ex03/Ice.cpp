#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "\x1b[33m""[Ice]: default constructor has called!""\x1b[0m" << std::endl;
}

Ice::Ice(Ice const &ref) : AMateria() {
	(void)ref;
	type = "ice";
	std::cout << "\x1b[35m""[Ice]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Ice::~Ice() {
	std::cout << "\x1b[31m""[Ice]: destructor has called!""\x1b[0m" << std::endl;
}

Ice&	Ice::operator=(Ice const &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[Ice]: assign operator has called!""\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[34m""[Ice]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

AMateria* Ice::clone() const {
	AMateria* ret = new Ice(*this);

	return (ret);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
