#include "easyfind.hpp"
#include <iostream>

// Codes ANSI pour les couleurs
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{
	std::cout << CYAN <<  "\n\n---- CREATION DU CONTAINER ----"<< RESET << std::endl;

    std::vector<int> vec;
	for(int i = 0; i < 5; i++)
		vec.push_back(i * 10);
	for(int i = 0; i < 5; i++)
		std::cout <<  vec[i] <<std::endl;

	std::cout << CYAN << "\n\n---- TEST VALEUR EXISTANTE DANS LE CONTAINER ----" << RESET <<std::endl;
	try
	{
		::easyfind(vec, 30);
		std::cout << "Value has been found" <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << CYAN << "\n\n---- TEST AVEC VALEUR INEXISTANTE DANS LE CONTAINER ----"<< RESET <<std::endl;
	try
	{
		::easyfind(vec, 34);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}