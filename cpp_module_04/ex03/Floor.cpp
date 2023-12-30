#include "Floor.hpp"

Floor::Floor() : len(0), arr() {
	std::cout << "\x1b[33m""[Floor]: default constructor has called!""\x1b[0m" << std::endl;
}

Floor::Floor(Floor const &ref) : len(ref.len) {
	std::cout << "\x1b[35m""[Floor]: deep-copy constructor has called!""\x1b[0m" << std::endl;
	for (int i = 0; i < len; i++) {
		arr[i] = ref.arr[i];
	}
}

Floor::~Floor() {
	std::cout << "\x1b[31m""[Floor]: destructor has called!""\x1b[0m" << std::endl;
	for (int i = 0; i < len; i++) {
		if (arr[i])
			delete arr[i];
	}
}

Floor&	Floor::operator=(Floor const &ref) {
	if (this != &ref) {
		//compose deep-copy with your own class!
		std::cout << "\x1b[34m""[Floor]: assign operator has called!""\x1b[0m" << std::endl;
		for (int i = 0; i < len; i++) {
			if (arr[i])
				delete arr[i];
		}
		len = ref.len;
		for (int i = 0; i < len; i++) {
			arr[i] = ref.arr[i];
		}
	}
	else
		std::cout << "\x1b[34m""[Floor]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

bool Floor::getMateria(AMateria* mat) {
	if (mat != NULL) {
		if (len < 100) {
			arr[len] = mat;
			len++;
			return (true);
		} else {
			std::cout << "The floor is filled with Materia!" << std::endl;
		}
	}
	return (false);
}
