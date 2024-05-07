#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		std::string _name;
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog const &copy);
		~Dog();
		Dog &operator=(Dog const &a);

		void makeSound() const;
};


#endif