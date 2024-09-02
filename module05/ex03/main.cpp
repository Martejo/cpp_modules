#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// ANSI color codes for colored output
#define RESET "\x1b[0m"
#define GREEN "\x1b[32;1m"
#define RED "\x1b[31;1m"
#define BLUE "\x1b[34;1m"
#define YELLOW "\x1b[33;1m"
#define MAGENTA "\x1b[35;1m"
#define CYAN "\x1b[36;1m"

void testInternCreation()
{
    std::cout << GREEN << "\n========================================" << RESET << std::endl;
    std::cout << GREEN << "           INTERN CREATION TEST          " << RESET << std::endl;
    std::cout << GREEN << "========================================\n" << RESET << std::endl;

    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");

    if (form)
    {
        std::cout << GREEN << "Form created: " << *form << RESET << std::endl;
        delete form;
    }

    std::cout << YELLOW << "\n--- Attempting to create an unknown form ---" << RESET << std::endl;

    try {
        form = someRandomIntern.makeForm("unknown form", "target");
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "========================================\n" << RESET << std::endl;
}

void testFormExecution()
{
    std::cout << BLUE << "\n========================================" << RESET << std::endl;
    std::cout << BLUE << "         FORM EXECUTION TESTS           " << RESET << std::endl;
    std::cout << BLUE << "========================================\n" << RESET << std::endl;

    Intern someRandomIntern;
    Bureaucrat highRank("HighRank", 1);
    Bureaucrat lowRank("LowRank", 150);

    AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

    if (form1) {
        highRank.signForm(*form1);
        highRank.executeForm(*form1);
        lowRank.executeForm(*form1);
        delete form1;
    }

    if (form2) {
        highRank.signForm(*form2);
        highRank.executeForm(*form2);
        lowRank.executeForm(*form2);
        delete form2;
    }

    if (form3) {
        highRank.signForm(*form3);
        highRank.executeForm(*form3);
        lowRank.executeForm(*form3);
        delete form3;
    }

    std::cout << BLUE << "========================================\n" << RESET << std::endl;
}

int main()
{
    testInternCreation();
    testFormExecution();
    
    return 0;
}
