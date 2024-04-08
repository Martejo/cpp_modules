#include <iostream>

int main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*brainPtr = &brain;
	std::string	&brainRef = brain;

	std::cout << "This is memory adress of brain string---> " << &brain << std::endl;
	std::cout << "This is memory adress held by stringPTR---> " << brainPtr << std::endl;
	std::cout << "This is memory adress held by stringREF---> " << &brainRef << std::endl;
	std::cout << std::endl;
	std::cout << "Value of brain---> " << brain << std::endl;
	std::cout << "Value pointed by stringPTR---> " << *brainPtr << std::endl;
	std::cout << "Value pointed by stringREF---> " << brainRef << std::endl;
	return (0);
}