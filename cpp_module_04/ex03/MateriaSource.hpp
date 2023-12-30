#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *source[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ref);
		~MateriaSource();

		MateriaSource&	operator=(const MateriaSource& ref);
		virtual void learnMateria(AMateria* mat);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
