#include <iostream>
#include <string>

int	main() {
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "The memory address of the string variable : ";
	std::cout << &str << std::endl;
	std::cout << "The memory address held by stringPTR : ";
	std::cout << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF : ";
	std::cout << &stringREF << std::endl;

	std::cout << "\nThe value of the string variable : ";
	std::cout << str << std::endl;
	std::cout << "The value pointed to by stringPTR : ";
	std::cout << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : ";
	std::cout << stringREF << std::endl;
}
