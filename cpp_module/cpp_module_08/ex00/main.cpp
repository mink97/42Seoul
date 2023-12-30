#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::deque<int> deq;
	std::list<int> ls;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		deq.push_back(i);
		ls.push_back(i);
	}

	try
	{
		std::cout << *::easyfind(vec, 11) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *::easyfind(deq, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *::easyfind(ls, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
