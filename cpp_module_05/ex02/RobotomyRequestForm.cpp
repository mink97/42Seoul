#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

/* Constructor and Destructor call */
RobotomyRequestForm::RobotomyRequestForm(std::string name) : \
AForm(name, 72, 45)
{
	std::cout << "\x1b[35m""[RobotomyRequestForm]: constructor has called!""\x1b[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) : AForm(ref)
{
	std::cout << "\x1b[35m""[RobotomyRequestForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\x1b[31m""[RobotomyRequestForm]: destructor has called!""\x1b[0m" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	(void)ref;
	return (*this);
}

/* execute function */
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false)
		throw IsNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::srand(std::time(NULL));
	double randNum = static_cast<double>(std::rand() % 10000) / 10000;
	std::cout << randNum << std::endl;
	if (randNum < 0.5)
	{
		std::cout << "Dr-r-r-r-r-r-r-r" << std::endl;
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << getName() << " failed to be robotomized" << std::endl;
	}
}
