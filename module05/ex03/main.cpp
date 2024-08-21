#include <exception>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define RESET "\x1b[0m"
# define GREEN "\e[1;32m"
# define RED "\x1b[31;1m"
# define BLUE "\x1b[34;1m"

int	main( void )
{
	Bureaucrat pedro("PedroTheBoss", 1);
	std::cout << GREEN << "\n----- OK TESTS -----!" << RESET << std::endl;
	std::cout << "\n" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		try 
		{
			std::cout << GREEN;
			rrf = someRandomIntern.makeForm("robotomy request", "Transformer");
			std::cout << BLUE;
			pedro.signForm(*rrf);
			pedro.executeForm(*rrf);
			delete rrf;
			std::cout << RESET;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "Exception catched : " << RESET << std::endl; 
		}
	}
	std::cout << "\n" << std::endl;
	{
		Intern someRandomIntern;
		AForm* scf;
		try 
		{
			std::cout << GREEN;
			scf = someRandomIntern.makeForm("shrubbery creation", "garden");
			std::cout << BLUE;
			pedro.signForm(*scf);
			pedro.executeForm(*scf);
			delete scf;
			std::cout << RESET;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "Exception catched : " << RESET << std::endl; 
		}
	}
	std::cout << "\n" << std::endl;
	{
		Intern someRandomIntern;
		AForm* ppf;
		try 
		{
			std::cout << GREEN;
			ppf = someRandomIntern.makeForm("presidential pardon", "prisoner");
			std::cout << BLUE;
			pedro.signForm(*ppf);
			pedro.executeForm(*ppf);
			delete ppf;
			std::cout << RESET;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "Exception catched : " << RESET << std::endl; 
		}
	}
	std::cout << "\n" << std::endl;
	std::cout << RED << "\n----- KO TEST -----" << RESET << std::endl;
	std::cout << "\n" << std::endl;
	{
		Intern someRandomIntern;
		AForm* badform;
		try 
		{
			std::cout << GREEN;
			badform = someRandomIntern.makeForm("bad form name", "Bender");
			std::cout << BLUE;
			pedro.signForm(*badform);
			pedro.executeForm(*badform);
			delete badform;
			std::cout << RESET;
		}
		catch (std::exception &e)
		{
			std::cout << RED << "Exception catched : " << e.what() << RESET << std::endl; 
		}
	}
	return (0);
}