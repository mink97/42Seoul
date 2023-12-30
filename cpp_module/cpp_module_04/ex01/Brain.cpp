#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "\x1b[33m""[Brain]: default constructor has called!""\x1b[0m" << std::endl;
}

Brain::Brain(std::string str) {
	for (int i = 0; i < 100; i++)
		ideas[i] = str;
	std::cout << "\x1b[33m""[Brain]: constructor has called!""\x1b[0m" << std::endl;
}

Brain::Brain(Brain const &ref) {
	for (int i = 0; i < 100; i++)
		ideas[i] = ref.ideas[i];
	std::cout << "\x1b[35m""[Brain]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Brain::~Brain() {
	std::cout << "\x1b[31m""[Brain]: destructor has called!""\x1b[0m" << std::endl;
}

Brain& Brain::operator=(Brain const &ref) {
	if (this != &ref) {
		for (int i = 0; i < 100; i++)
			ideas[i] = ref.ideas[i];
		std::cout << "\x1b[34m""[Brain]: assign operator has called!""\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[34m""[Brain]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void Brain::setIdea(int i, std::string idea) {
	if (i < 0 || i >= 100) {
		std::cout << "out of index" << std::endl;
		return ;
	}
	ideas[i] = idea;
}

std::string Brain::getIdea(int i) {
	if (i < 0 || i >= 100) {
		std::cout << "out of index" << std::endl;
		return "";
	}
	return (ideas[i]);
}
