#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(std::string type);
		Animal( Animal &copy );
		virtual ~Animal();
		Animal	&operator=( Animal &a);

		virtual void	makeSound() const;
		std::string getType() const;
};

#endif