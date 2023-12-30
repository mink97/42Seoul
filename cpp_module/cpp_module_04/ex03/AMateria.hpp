#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
	protected:
		std::string type;

	public:
		AMateria();
		AMateria(const AMateria& ref);
		AMateria(std::string const& type);
		virtual ~AMateria();

		AMateria& operator=(const AMateria& ref);

		std::string const& getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#include "Character.hpp"

#endif
