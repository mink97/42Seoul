#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	PhoneBook	phonebook;

	std::cout << "choose action from the options" << std::endl;
	std::cout << "1. ADD 2. SEARCH 3. EXIT" << std::endl;
	std::string	option;
	while (std::getline(std::cin, option))
	{
		if (option == "1") {
			phonebook.add_contact();
		} else if (option == "2") {
			phonebook.show();
			std::cout << "Please choose the number of the contact you would like to see." << std::endl;
			std::string	n;
			std::getline(std::cin, n);
			if (n.length() == 1 && n[0] >= '1' && n[0] <= '8')
				phonebook.show_details(stoi(n) - 1);
			else
				std::cout << "invalid input." << std::endl;
		} else if (option == "3") {
			std::cout << "the program will exit" << std::endl;
			break;
		} else {
			std::cout << "your input is not valid. please enter a different value." << std::endl;
		}
		std::cout << "\nchoose action from the options" << std::endl;
		std::cout << "1. ADD 2. SEARCH 3. EXIT" << std::endl;
	}
	return (0);
}
