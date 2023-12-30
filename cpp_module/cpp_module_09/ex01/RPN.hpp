#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
	private:

	public:
		RPN();
		RPN(const RPN& ref);
		~RPN();

		RPN&	operator=(const RPN& ref);
		static int calculte(std::string arg);
};

#endif
