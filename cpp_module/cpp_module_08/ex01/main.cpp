#include <ctime>
#include <cstdlib>
#include "Span.hpp"

int main()
{
	std::srand(std::time(NULL));
	Span sp = Span(10000);

	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp.addRange(10000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		sp.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "shortest span is " << sp.shortestSpan() << std::endl;
	std::cout << "longest span is " << sp.longestSpan() << std::endl;
	return 0;
}
