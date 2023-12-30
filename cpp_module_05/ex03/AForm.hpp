#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		const int _requiredGrade;
		const int _executeGrade;
		std::string _type;
		bool _isSigned;

		AForm();
		AForm&	operator=(const AForm& ref);
	public:
		void beSigned(const Bureaucrat& br);
		virtual void execute(Bureaucrat const & executor) const = 0;

		const int& getRequiredGrade() const;
		const int& getExecuteGrade() const;
		const std::string& getType() const;
		const std::string& getName() const;
		const bool& getIsSigned() const;
		void setType(const std::string& type);

		AForm(std::string name, int requiredGrade, int executeGrade);
		AForm(const AForm& ref);
		virtual ~AForm();

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

		class IsNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif
