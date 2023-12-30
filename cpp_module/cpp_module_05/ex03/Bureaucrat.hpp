#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

		Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& ref);
	public:
		void signForm(AForm& form);
		void executeForm(AForm const& form);
		void incrementGrade();
		void decrementGrade();

		const std::string& getName() const;
		const int& getGrade() const;

		Bureaucrat(const std::string str, const int n);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);

#endif
