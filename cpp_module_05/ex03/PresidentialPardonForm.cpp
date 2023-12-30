#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

/* Constructor and Destructor call */
PresidentialPardonForm::PresidentialPardonForm(std::string name) : \
AForm(name, 25, 5)
{
	setType("PresidentialPardonForm");
	std::cout << "\x1b[35m""[PresidentialPardonForm]: constructor has called!""\x1b[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref) : AForm(ref)
{
	std::cout << "\x1b[35m""[PresidentialPardonForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\x1b[31m""[PresidentialPardonForm]: destructor has called!""\x1b[0m" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
	(void)ref;
	return (*this);
}

/* execute function */
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false)
		throw IsNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
