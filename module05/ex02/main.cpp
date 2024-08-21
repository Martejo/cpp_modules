#include <exception>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define RESET "\x1b[0m"
# define GREEN "\e[1;32m"
# define RED "\x1b[31;1m"
# define BLUE "\x1b[34;1m"

int	main( void )
{

	std::cout << GREEN << "\n!----- WORKING TESTS -----!" << RESET << std::endl;
	{
		Bureaucrat				Tito("Tito", 1);

		PresidentialPardonForm	pres_form("presidential pardon", "prisoner");
		RobotomyRequestForm		rob_form("Robotomy", "patient_105");
		ShrubberyCreationForm	shru_form("shrubbery", "garden");

		std::cout << "\n" << std::endl;
		std::cout << BLUE << std::endl;
		Tito.signForm(rob_form);
		Tito.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		Tito.signForm(shru_form);
		Tito.executeForm(shru_form);

		std::cout << "\n" << std::endl;
		Tito.signForm(pres_form);
		Tito.executeForm(pres_form);
		std::cout << RESET << std::endl;
		std::cout << "\n" << std::endl;

	}

	std::cout << RED << "\n!----- FAILING TESTS : SIGNATURE -----!" << RESET << std::endl;
	{
		Bureaucrat				Pedro("Pedro", 1);
		PresidentialPardonForm	pres_form("presidential pardon", "prisoner");
		RobotomyRequestForm		rob_form("Robotomy", "patient_105");
		ShrubberyCreationForm	shru_form("shrubbery", "garden");


		std::cout << "\n" << std::endl;
		std::cout << BLUE << std::endl;
		Pedro.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		Pedro.executeForm(shru_form);

		std::cout << "\n" << std::endl;
		Pedro.executeForm(pres_form);
		std::cout << RESET << std::endl;
		std::cout << "\n" << std::endl;

	}

	std::cout << RED << "\n!----- FAILING TESTS : GRADE -----!" << RESET << std::endl;
	{
		Bureaucrat				Jeannot("Jeannot", 150);
		Bureaucrat				Rico("Rico", 1);
		PresidentialPardonForm	pres_form("presidential pardon", "prisoner");
		RobotomyRequestForm		rob_form("Robotomy", "patient_105");
		ShrubberyCreationForm	shru_form("shrubbery", "garden");

		std::cout << "\n" << std::endl;
		std::cout << BLUE << std::endl;
		Rico.signForm(rob_form);
		Jeannot.executeForm(rob_form);

		std::cout << "\n" << std::endl;
		Rico.signForm(shru_form);
		Jeannot.executeForm(shru_form);

		std::cout << "\n" << std::endl;
		Rico.signForm(pres_form);
		Jeannot.executeForm(pres_form);
		std::cout << RESET << std::endl;
		std::cout << "\n" << std::endl;

	}
	return (0);
}