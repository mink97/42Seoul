#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		const int _requiredGrade;
		const int _executeGrade;
		bool _isSigned;

		Form();
		Form&	operator=(const Form& ref);
	public:
		void beSigned(const Bureaucrat& br);

		const int& getRequiredGrade() const;
		const int& getExecuteGrade() const;
		const std::string& getName() const;
		const bool& getIsSigned() const;

		Form(std::string name, int requiredGrade, int executeGrade);
		Form(const Form& ref);
		~Form();

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
