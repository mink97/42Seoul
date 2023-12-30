#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];

	public:
		Character();
		Character(std::string const& name);
		Character(const Character& ref);
		~Character();

		Character&	operator=(const Character& ref);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* mat);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		virtual AMateria* getAddress(int idx);
};

#endif
