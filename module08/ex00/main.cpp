#include "easyfind.hpp"
#include <iostream>

int main()
{
	std::cout << "\n\n---- CREATION DU CONTAINER ----"<<std::endl;

    std::vector<int> vec;
	for(int i = 0; i < 5; i++)
		vec.push_back(i * 10);
	for(int i = 0; i < 5; i++)
		std::cout << vec[i] <<std::endl;

	std::cout << "\n\n---- TEST VALEUR EXISTANTE DANS LE CONTAINER ----"<<std::endl;
	try
	{
		::easyfind(vec, 30);
		std::cout << "Value has been found" <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n\n---- TEST AVEC VALEUR INEXISTANTE DANS LE CONTAINER ----"<<std::endl;
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