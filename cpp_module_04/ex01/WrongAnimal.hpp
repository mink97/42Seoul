#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
	std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& ref);
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& ref);
		void makeSound() const;
		std::string getType() const;
};

#endif
