#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	Animal **animals = new Animal*[20];

	for (int i = 0; i < 20; i++)
	{
		std::cout << "number " << i+1 << std::endl;
		if (i % 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}

	animals[3]->showIdea(3);
	animals[4]->showIdea(3);

	for (int i = 0; i < 20; i++) {
		std::cout << "number " << i+1 << std::endl;
		delete animals[i];
	}
	delete[] animals;
}
