#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		std::string _name;
		Brain		*_brain;
	
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog const &copy);
		virtual ~Dog();
		Dog &operator=(Dog const &a);

		void makeSound() const;
		Brain const	*getBrain() const;
};


#endif