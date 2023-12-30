#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
	index = 0;
}

std::string	PhoneBook::print_in_column(std::string s) {
	if (s.length() >= 10) {
		return (s.substr(0, 9) + ".");
	}
	else
		return (s);
}

void	PhoneBook::add_contact() {
	Contact	tmp;
	if (tmp.set_first_name() ||
		tmp.set_last_name() ||
		tmp.set_nickname() ||
		tmp.set_phone_number() ||
		tmp.set_darkest_secret()) {
		std::cout << "\nfailed to add contact" << std::endl;
		return ;
	}
	tmp.is_filled();
	contacts[index++] = tmp;
	if (index == 8)
		index = 0;
}

void	PhoneBook::show() {
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << print_in_column(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << print_in_column(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << print_in_column(contacts[i].get_nickname()) << "|";
		std::cout << std::endl;
	}
}

void	PhoneBook::show_details(int	index) {
	if (contacts[index].is_empty()) {
		std::cout << "the selected number is empty." << std::endl;
		return;
	}
	std::cout << "first name : " << contacts[index].get_first_name() << std::endl;
	std::cout << "last name : " <<  contacts[index].get_last_name() << std::endl;
	std::cout << "nick name : " <<  contacts[index].get_nickname() << std::endl;
	std::cout << "phone number : " <<  contacts[index].get_phone_number() << std::endl;
	std::cout << "darkest secret : " <<  contacts[index].get_darkest_secret() << std::endl;
}
