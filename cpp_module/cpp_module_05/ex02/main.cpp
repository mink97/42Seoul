#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat ming("ming", 1);
	Bureaucrat kang("kang", 20);
	Bureaucrat yooh("yooh", 50);
	Bureaucrat jpark2("jpark2", 140);

	AForm* sForm = new ShrubberyCreationForm("sform");
	AForm* rForm = new RobotomyRequestForm("rform");
	AForm* pForm = new PresidentialPardonForm("pform");

	std::cout << "----------Bureaucrat report----------" << std::endl;
	std::cout << ming << std::endl;
	std::cout << kang << std::endl;
	std::cout << yooh << std::endl;
	std::cout << jpark2 << std::endl;

	std::cout << "----------Form report----------" << std::endl;
	std::cout << *sForm << std::endl;
	std::cout << *rForm << std::endl;
	std::cout << *pForm << std::endl;

	std::cout << "\n----------sign----------" << std::endl;
	yooh.signForm(*sForm);
	yooh.signForm(*rForm);
	yooh.signForm(*pForm);
	kang.signForm(*pForm);
	std::cout << "\n----------execute----------" << std::endl;
	jpark2.executeForm(*sForm);
	jpark2.executeForm(*rForm);
	jpark2.executeForm(*pForm);
	delete sForm;
	delete rForm;
	delete pForm;
}
