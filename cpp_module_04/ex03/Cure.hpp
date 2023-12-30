#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	private:

	public:
		Cure();
		Cure(const Cure& ref);
		~Cure();

		Cure&	operator=(const Cure& ref);
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
