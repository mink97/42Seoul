#include "Form.hpp"

/* Constructor and Destructor call */
Form::Form() : _requiredGrade(0), _executeGrade(0) {}

Form::Form(std::string name, int requiredGrade, int executeGrade) : \
	_name(name), _requiredGrade(requiredGrade), _executeGrade(executeGrade), _isSigned(false)
{
	if (getRequiredGrade() < 1 || getExecuteGrade() < 1)
		throw Form::GradeTooHighException();
	if (getRequiredGrade() > 150 || getExecuteGrade() > 150)
		throw Form::GradeTooLowException();
	std::cout << "\x1b[35m""[Form]: constructor has called!""\x1b[0m" << std::endl;
}

Form::Form(Form const &ref) : _name(ref.getName()), _requiredGrade(ref.getRequiredGrade()), \
	_executeGrade(ref.getExecuteGrade()), _isSigned(false)
{
	if (getRequiredGrade() < 1 || getExecuteGrade() < 1)
		throw Form::GradeTooHighException();
	if (getRequiredGrade() > 150 || getExecuteGrade() > 150)
		throw Form::GradeTooLowException();
	std::cout << "\x1b[35m""[Form]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Form::~Form()
{
	std::cout << "\x1b[31m""[Form]: destructor has called!""\x1b[0m" << std::endl;
}

/* exception */
const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high![Form]");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too Low![Form]");
}

/* getter & setter functions */
const int& Form::getRequiredGrade() const
{
	return (_requiredGrade);
}

const int& Form::getExecuteGrade() const
{
	return (_executeGrade);
}

const std::string& Form::getName() const
{
	return (_name);
}

const bool& Form::getIsSigned() const
{
	return (_isSigned);
}

/* member function */
void Form::beSigned(const Bureaucrat& br)
{
	if (getRequiredGrade() >= br.getGrade())
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

/* insertion operator */
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "name : " << form.getName() << std::endl
		<< "requiredGrade : " << form.getRequiredGrade() << std::endl
		<< "executeGrade : " << form.getExecuteGrade() << std::endl
		<< "isSigned : " << std::boolalpha << form.getIsSigned();
	return (os);
}

Form&	Form::operator=(Form const &ref)
{
	(void)ref;
	return (*this);
}
