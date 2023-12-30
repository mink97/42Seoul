#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class	PhoneBook {
	private:
		Contact	contacts[8];
		int		index;
		std::string	print_in_column(std::string s);
	public:
		PhoneBook();
		void	add_contact();
		void	show();
		void	show_details(int index);
};

#endif
