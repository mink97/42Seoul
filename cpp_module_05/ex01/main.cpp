#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat ming("ming", 30);
	Bureaucrat kang("kang", 130);
	Form form1("report", 40, 100);

	std::cout << "----------constructor exception----------" << std::endl;
	try
	{
		Form form("garbage file", 200, 200);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "\n----------form1----------" << std::endl;
	std::cout << form1 << std::endl;

	std::cout << "\n----------kang signed form1----------" << std::endl;
	kang.signForm(form1);
	std::cout << form1 << std::endl;
	std::cout << "\n----------ming signed form1----------" << std::endl;
	ming.signForm(form1);
	std::cout << form1 << std::endl;
}
