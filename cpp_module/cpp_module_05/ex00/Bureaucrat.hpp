#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

		Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& ref);
	public:
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

		const std::string& getName() const;
		const int& getGrade() const;

		void incrementGrade();
		void decrementGrade();

		Bureaucrat(const std::string str, const int n);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);

#endif
