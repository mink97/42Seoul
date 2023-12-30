#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(std::string str);
		Brain(const Brain& ref);
		~Brain();

		Brain&	operator=(const Brain& ref);

		void setIdea(int i, std::string idea);
		std::string getIdea(int i);
};

#endif
