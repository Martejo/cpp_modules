# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
		std::string	_name;
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &a);
		~WrongCat();

		void makeSound() const;
};


# endif