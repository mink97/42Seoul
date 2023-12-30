#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

	public:
		virtual void execute(Bureaucrat const & executor) const;

		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		~RobotomyRequestForm();
};

#endif
