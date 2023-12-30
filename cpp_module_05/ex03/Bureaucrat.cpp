#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, const int n) : _name(name)
{
	if (n < 1)
		throw Bureaucrat::GradeTooHighException();
	if (n > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = n;
	std::cout << "\x1b[35m""[Bureaucrat]: constructor has called!""\x1b[0m" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : _name(ref.getName()), _grade(ref.getGrade())
{
	if (getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "\x1b[35m""[Bureaucrat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\x1b[31m""[Bureaucrat]: destructor has called!""\x1b[0m" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &ref)
{
	(void)ref;
	return (*this);
}

const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

const int& Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() \
		<< " because " << e.what() << ".\n";
	}
}

void Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't execute " << form.getName() \
		<< " because " << e.what() << ".\n";
	}

}

void Bureaucrat::incrementGrade()
{
	if (this->getGrade() <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->getGrade() >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The Bureaucrat grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The Bureaucrat grade is too Low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br)
{
	os << br.getName() << ", bureaucrat grade " << br.getGrade() << ".";
	return (os);
}
