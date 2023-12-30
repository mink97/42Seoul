#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "----------list----------" << std::endl;
	{
		std::list<int> ls;
		ls.push_back(5);
		ls.push_back(17);
		std::cout << "list.back: " << ls.back() << std::endl;
		ls.pop_back();
		std::cout << "size: " << ls.size() << std::endl;
		ls.push_back(3);
		ls.push_back(5);
		ls.push_back(737);
		ls.push_back(0);
		std::list<int>::iterator it = ls.begin();
		std::list<int>::iterator ite = ls.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(ls);
	}
	return 0;
}
