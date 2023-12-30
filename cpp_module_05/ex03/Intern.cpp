#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "\x1b[33m""[Intern]: default constructor has called!""\x1b[0m" << std::endl;
}

Intern::Intern(Intern const &ref)
{
	(void)ref;
	std::cout << "\x1b[35m""[Intern]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Intern::~Intern()
{
	std::cout << "\x1b[31m""[Intern]: destructor has called!""\x1b[0m" << std::endl;
}

Intern&	Intern::operator=(Intern const &ref)
{
	if (this != &ref)
		std::cout << "\x1b[34m""[Intern]: assign operator has called!""\x1b[0m" << std::endl;
	else
		std::cout << "\x1b[34m""[Intern]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

AForm* Intern::makeForm(std::string type, std::string name)
{
	std::string typeArr[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (type == typeArr[i])
			{
				switch (i)
				{
				case 0:
					return (new PresidentialPardonForm(name));
				case 1:
					return (new RobotomyRequestForm(name));
				case 2:
					return (new ShrubberyCreationForm(name));
				default:
					break;
				}
			}
		}
		throw WrongTypeException();
	}
	catch(const std::exception& e)
	{
		std::cout << "intern failed to make " << type << " Form because " << e.what() << '\n';
	}
	return (NULL);
}

const char* Intern::WrongTypeException::what() const throw()
{
	return ("that type isn't exist");
}
