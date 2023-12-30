#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);

	public:
		virtual void execute(Bureaucrat const & executor) const;

		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		~PresidentialPardonForm();
};

#endif
