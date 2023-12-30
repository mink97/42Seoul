#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "\x1b[33m""[MateriaSource]: default constructor has called!""\x1b[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		source[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &ref) {
	std::cout << "\x1b[35m""[MateriaSource]: deep-copy constructor has called!""\x1b[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (ref.source[i])
			source[i] = ref.source[i]->clone();
		else
			source[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "\x1b[31m""[MateriaSource]: destructor has called!""\x1b[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (source[i])
			delete source[i];
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const &ref) {
	if (this != &ref) {
		std::cout << "\x1b[34m""[MateriaSource]: assign operator has called!""\x1b[0m" << std::endl;
		for (int i = 0; i < 4; i++) {
			if (source[i])
				delete source[i];
			if (ref.source[i])
				source[i] = ref.source[i]->clone();
			else
				source[i] = NULL;
		}
	}
	else
		std::cout << "\x1b[34m""[MateriaSource]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* mat) {
	int i = 0;

	for (; i < 4; i++) {
		if (!source[i]) {
			source[i] = mat->clone();
			break;
		}
	}
	if (i == 4) {
		std::cout << "The available slots for learning are full!" << std::endl;
	}
	delete mat;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (source[i]->getType() == type) {
			return (source[i]->clone());
		}
	}
	return (0);
}
