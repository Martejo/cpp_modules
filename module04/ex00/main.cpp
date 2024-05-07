#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


/**
* Notions:
* 1. Inheritance
* Inheritance allows a class to derive from (or “inherit”)
* the properties and methods of another class.
*
* 2. Polymorphism
* Polymorphism is the ability of a message (such as a method or function)
* to be processed differently depending on the object receiving it. 
*
*3. Abstract classes and virtual functions
*
* An abstract class is a class that is not intended to be
* instantiated directly, but rather inherited by other classes.
* It is often used to define a basic interface for derived classes.
* In C++, a class is made abstract by declaring at least
* one of its functions as pure virtual.
*
* In the case of inheritance, the destructor mother must be virtual.
*/

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;

	std::cout << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();  //K will use the method of the WrongAnimal class instead of the wrgcat class

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;

	return (0);
}