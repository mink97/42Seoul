#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

/* Constructor and Destructor call */
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : \
AForm(name, 145, 137)
{
	std::cout << "\x1b[35m""[ShrubberyCreationForm]: constructor has called!""\x1b[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref) : AForm(ref)
{
	std::cout << "\x1b[35m""[ShrubberyCreationForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\x1b[31m""[ShrubberyCreationForm]: destructor has called!""\x1b[0m" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
	(void)ref;
	return (*this);
}

/* execute function */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false)
		throw IsNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream	out(getName() + "_shrubbery");
	if (out.is_open() == false)
		throw FileOpenException();
	std::string content =
"                                                         .\n"
"                                              .         ;  \n"
"                 .              .              ;%     ;;   \n"
"                   ,           ,                :;%  %;   \n"
"                    :         ;                   :;%;'     .,   \n"
"           ,.        %;     %;            ;        %;'    ,;\n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'   \n"
"                        `@%.  `;@%.      ;@@%;         \n"
"                          `@%%. `@%%    ;@@%;        \n"
"                            ;@%. :@%%  %@@%;       \n"
"                              %@bd%%%bd%%:;     \n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '         \n"
"                                %@@@o%;:(.,'         \n"
"                            `.. %@@@o%::;         \n"
"                               `)@@@o%::;         \n"
"                                %@@(o)::;        \n"
"                               .%@@@@%::;         \n"
"                               ;%@@@@%::;.          \n"
"                              ;%@@@@%%:;;;. \n"
"                          ...;%@@@@@%%:;;;;,..    \n";
	out << content;
	out.close();
}

/* exception */
const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("failed to open file");
}
