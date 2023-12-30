#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "----------animal----------" << std::endl;
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "----------type----------" << std::endl;
	std::cout << "Dog : " << j->getType() << " " << std::endl;
	std::cout << "Cat : " << i->getType() << " " << std::endl;
	std::cout << "----------make sound----------" << std::endl;
	std::cout << "Dog : ";
	j->makeSound();
	std::cout << "Cat : ";
	i->makeSound(); //will output the cat sound!
	std::cout << "Animal : ";
	// meta->makeSound();
	std::cout << "----------delete----------" << std::endl;
	// delete meta;
	delete j;
	delete i;
}
