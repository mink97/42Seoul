#include "AMateria.hpp"

AMateria::AMateria() : type("default") {
	std::cout << "\x1b[33m""[AMateria]: default constructor has called!""\x1b[0m" << std::endl;
}

AMateria::AMateria(AMateria const &ref) : type(ref.type) {
	std::cout << "\x1b[35m""[AMateria]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << "\x1b[35m""[AMateria]: " << type  << " type constructor has called!""\x1b[0m" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "\x1b[31m""[AMateria]: destructor has called!""\x1b[0m" << std::endl;
}

AMateria&	AMateria::operator=(AMateria const &ref) {
	if (this != &ref) {
		type = ref.type;
		std::cout << "\x1b[34m""[AMateria]: assign operator has called!""\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[34m""[AMateria]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

std::string const& AMateria::getType() const {
	return (type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "<nothing happened>" << std::endl;
}
