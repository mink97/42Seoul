#include "AForm.hpp"

/* Constructor and Destructor call */
AForm::AForm(std::string name, int requiredGrade, int executeGrade) : \
	_name(name), _requiredGrade(requiredGrade), _executeGrade(executeGrade), _type("AFORM"), _isSigned(false)
{
	if (getRequiredGrade() < 1 || getExecuteGrade() < 1)
		throw AForm::GradeTooHighException();
	if (getRequiredGrade() > 150 || getExecuteGrade() > 150)
		throw AForm::GradeTooLowException();
	std::cout << "\x1b[35m""[AForm]: constructor has called!""\x1b[0m" << std::endl;
}

AForm::AForm(AForm const &ref) : _name(ref.getName()), _requiredGrade(ref.getRequiredGrade()), \
	_executeGrade(ref.getExecuteGrade()), _type(ref.getType()), _isSigned(false)
{
	if (getRequiredGrade() < 1 || getExecuteGrade() < 1)
		throw AForm::GradeTooHighException();
	if (getRequiredGrade() > 150 || getExecuteGrade() > 150)
		throw AForm::GradeTooLowException();
	std::cout << "\x1b[35m""[AForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

AForm::~AForm()
{
	std::cout << "\x1b[31m""[AForm]: destructor has called!""\x1b[0m" << std::endl;
}

/* exception */
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high![AForm]");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too Low![AForm]");
}

const char* AForm::IsNotSignedException::what() const throw()
{
	return ("This form is not signed");
}

/* getter & setter functions */
const int& AForm::getRequiredGrade() const
{
	return (_requiredGrade);
}

const int& AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

const std::string& AForm::getName() const
{
	return (_name);
}

const bool& AForm::getIsSigned() const
{
	return (_isSigned);
}

const std::string& AForm::getType() const
{
	return (_type);
}

void AForm::setType(const std::string& type)
{
	_type = type;
}

/* member function */
void AForm::beSigned(const Bureaucrat& br)
{
	if (getRequiredGrade() < br.getGrade())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

/* insertion operator */
std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "name : " << Aform.getName() << std::endl
		<< "requiredGrade : " << Aform.getRequiredGrade() << std::endl
		<< "executeGrade : " << Aform.getExecuteGrade() << std::endl
		<< "isSigned : " << std::boolalpha << Aform.getIsSigned();
	return (os);
}

AForm&	AForm::operator=(AForm const &ref)
{
	(void)ref;
	return (*this);
}
