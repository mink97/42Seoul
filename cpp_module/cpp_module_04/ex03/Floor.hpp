#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Floor {
	private:
		int len;
		AMateria* arr[100];

	public:
		Floor();
		Floor(const Floor& ref);
		~Floor();

		Floor& operator=(const Floor& ref);
		bool getMateria(AMateria* mat);
};

#endif
