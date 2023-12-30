#include "Contact.hpp"

Contact::Contact() {
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
	empty = true;
}

void	Contact::is_filled() {
	empty = false;
}

bool	Contact::is_empty() {
	return (empty);
}

int	Contact::set_first_name() {
	std::string	name;
	std::cout << "what is first name? : ";
	while (std::getline(std::cin, name)) {
		if (name.empty()) {
			std::cout << "it is empty. please enter again." << std::endl;
			std::cout << "what is first name? : ";
			continue;
		}
		first_name = name;
		return (0);
	}
	return (1);
}

int	Contact::set_last_name() {
	std::string	name;
	std::cout << "what is last name? : ";
	while (std::getline(std::cin, name)) {
		if (name.empty()) {
			std::cout << "it is empty. please enter again." << std::endl;
			std::cout << "what is last name? : ";
			continue;
		}
		last_name = name;
		return (0);
	}
	return (1);
}

int	Contact::set_nickname() {
	std::string	name;
	std::cout << "what is nickname? : ";
	while (std::getline(std::cin, name)) {
		if (name.empty()) {
			std::cout << "it is empty. please enter again." << std::endl;
			std::cout << "what is nickname? : ";
			continue;
		}
		nickname = name;
		return (0);
	}
	return (1);
}

int	Contact::set_phone_number() { // 숫자만 오게 수정해야 함.
	std::string	name;
	std::cout << "what is phone number? : ";
	while (std::getline(std::cin, name)) {
		std::size_t	found;
		found = name.find_first_not_of("0123456789");
		if (found != std::string::npos) {
			std::cout << "the phone number should only contain numbers." << std::endl;
			std::cout << "what is phone number? : ";
			continue;
		} else if (name.empty()) {
			std::cout << "it is empty. please enter again." << std::endl;
			std::cout << "what is phone number? : ";
			continue;
		}
		phone_number = name;
		return (0);
	}
	return (1);
}

int	Contact::set_darkest_secret() {
	std::string	name;
	std::cout << "what is darkest secret? : ";
	if (std::getline(std::cin, name)) {
		darkest_secret = name;
		return (0);
	}
	return (1);
}

std::string	Contact::get_first_name() {
	return first_name;
}

std::string	Contact::get_last_name() {
	return last_name;
}

std::string	Contact::get_nickname() {
	return nickname;
}

std::string	Contact::get_phone_number() {
	return phone_number;
}

std::string	Contact::get_darkest_secret() {
	return darkest_secret;
}
