#include "Bureaucrat.hpp"

// ANSI color codes for colored output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

int main()
{

/******************************************************/

	std::cout << BOLD << "\n-------CONSTRUCT WITH GRADE TOO LOW----------\n" << RESET << std::endl;
	try {
		std::cout << YELLOW << "Attempting to construct bureaucrat (name: Brad Pitt, grade: 151)" << RESET << std::endl;
		Bureaucrat a("Brad Pitt", 151);
	} 
	catch (const std::exception& e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

/******************************************************/

	std::cout << BOLD << "\n-------CONSTRUCT WITH GRADE TOO HIGH----------\n" << RESET << std::endl;
	try {
		std::cout << YELLOW << "Attempting to construct bureaucrat (name: Garrosh Hurlenfer, grade: 0)" << RESET << std::endl;
		Bureaucrat b("Garrosh Hurlenfer", 0);
	} 
	catch (const std::exception& e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

/******************************************************/

	std::cout << BOLD << "\n-------CONSTRUCT WITH GRADE OK----------\n" << RESET << std::endl;
	try {
		std::cout << YELLOW << "Constructing bureaucrat (name: Michelle Leblanc, grade: 1)" << RESET << std::endl;
		Bureaucrat c("Michelle Leblanc", 1);
		std::cout << GREEN << c << " constructed successfully!" << RESET << std::endl;
	} 
	catch (const std::exception& e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

/****************************************************/

	std::cout << BOLD << "\n-------TEST OPERATORS----------\n" << RESET << std::endl;

	Bureaucrat d("Ezio", 150);
	Bureaucrat d2("Altair", 112);
	std::cout << YELLOW << "Assigning " << d << " to " << d2 << RESET << std::endl;
	d2 = d;
	std::cout << GREEN << "After assignment: " << d2 << RESET << std::endl;

/******************************************************/

	std::cout << BOLD << "\n-------TEST INCREMENT AND DECREMENT----------\n" << RESET << std::endl;

	std::cout << BOLD << "\n-------MODIFY GRADE TOO LOW----------\n" << RESET << std::endl;
	try {
		std::cout << YELLOW << "Before decrement: " << d << RESET << std::endl;
		d.decrementGrade();
	} 
	catch (const std::exception& e) {
		std::cerr << RED << "Exception caught: Decrement failed: " << e.what() << RESET << std::endl;
	} 
	std::cout << GREEN << "After decrement attempt: " << d << RESET << std::endl;

/******************************************************/

	std::cout << BOLD << "\n-------MODIFY GRADE TOO HIGH----------\n" << RESET << std::endl;

	d.validateGrade(1);
	try {
		std::cout << YELLOW << "Before increment: " << d << RESET << std::endl;
		d.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception caught: Increment failed: " << e.what() << RESET << std::endl;
	} 
	std::cout << GREEN << "After increment attempt: " << d << RESET << std::endl;

/******************************************************/

	std::cout << BOLD << "\n-------MODIFY GRADE OK----------\n" << RESET << std::endl;

	d.validateGrade(100);
	try {
		std::cout << YELLOW << "Before decrement: " << d << RESET << std::endl;
		d.decrementGrade();
	} 
	catch (const std::exception& e) {
		std::cerr << RED << "Exception caught: Decrement failed: " << e.what() << RESET << std::endl;
	} 
	std::cout << GREEN << "After decrement: " << d << RESET << std::endl;

	try {
		std::cout << YELLOW << "Before increment: " << d << RESET << std::endl;
		d.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Exception caught: Increment failed: " << e.what() << RESET << std::endl;
	} 
	std::cout << GREEN << "After increment: " << d << RESET << std::endl;

/******************************************************/

	std::cout << BOLD << "\n-------PROGRAM END----------\n" << RESET << std::endl;

	return (0);
}
