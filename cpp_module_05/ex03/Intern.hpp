#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern& ref);
		~Intern();

		AForm* makeForm(std::string type, std::string name);

		Intern&	operator=(const Intern& ref);

		class WrongTypeException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
