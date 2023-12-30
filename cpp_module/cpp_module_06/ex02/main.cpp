#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	std::srand(std::time(NULL));
	int n = rand() % 3;
	switch (n)
	{
	case 0:
		std::cout << "generate A Class" << std::endl;
		return (new A);
	case 1:
		std::cout << "generate B Class" << std::endl;
		return (new B);
	case 2:
		std::cout << "generate C Class" << std::endl;
		return (new C);
	default:
		break;
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "It's actual type is A." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "It's actual type is B." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "It's actual type is C." << std::endl;
	else
		std::cout << "" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "It's actual type is A." << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "It's actual type is B." << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "It's actual type is C." << std::endl;
	}
	catch(const std::exception& e) {}




}

int main()
{
	Base* test = generate();

	identify(test);
	identify(*test);

	delete test;
}
