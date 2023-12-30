#include "Bureaucrat.hpp"

int main() {
	std::cout << "----------TooHighException----------" << std::endl;
	try
	{
		Bureaucrat b1("ming", -2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "----------TooLowException----------" << std::endl;
	try
	{
		Bureaucrat b2("kang", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "----------TooHighException----------" << std::endl;
	Bureaucrat b1("ming", 1);
	std::cout << b1 << std::endl;
	try
	{
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "----------TooLowException----------" << std::endl;
	Bureaucrat b2("kang", 149);
	std::cout << b2 << std::endl;
	try
	{
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

}
