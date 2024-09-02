#include <exception>
#include "Bureaucrat.hpp"
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

void workingTests()
{
    std::cout << GREEN << "\n========================================" << RESET << std::endl;
    std::cout << GREEN << "          WORKING TESTS STARTING        " << RESET << std::endl;
    std::cout << GREEN << "========================================\n" << RESET << std::endl;

    Bureaucrat Tito("Tito", 1);

    PresidentialPardonForm pres_form("Prisoner");
    RobotomyRequestForm rob_form("Patient_105");
    ShrubberyCreationForm shru_form("Garden");

    std::cout << BLUE << "\n--- Signing and Executing RobotomyRequestForm ---" << RESET << std::endl;
    Tito.signForm(rob_form);
    Tito.executeForm(rob_form);

    std::cout << BLUE << "\n--- Signing and Executing ShrubberyCreationForm ---" << RESET << std::endl;
    Tito.signForm(shru_form);
    Tito.executeForm(shru_form);

    std::cout << BLUE << "\n--- Signing and Executing PresidentialPardonForm ---" << RESET << std::endl;
    Tito.signForm(pres_form);
    Tito.executeForm(pres_form);

    std::cout << GREEN << "\n========================================" << RESET << std::endl;
    std::cout << GREEN << "           WORKING TESTS FINISHED       " << RESET << std::endl;
    std::cout << GREEN << "========================================\n" << RESET << std::endl;
	std::cout << CYAN << "===DESTRUCTOR CALLING===\n" << RESET << std::endl;
}

void failingSignatureTests()
{
    std::cout << RED << "\n========================================" << RESET << std::endl;
    std::cout << RED << "    FAILING TESTS: EXECUTING WITHOUT SIGNATURE" << RESET << std::endl;
    std::cout << RED << "========================================\n" << RESET << std::endl;

    Bureaucrat Pedro("Pedro", 1);
    PresidentialPardonForm pres_form("Prisoner");
    RobotomyRequestForm rob_form("Patient_105");
    ShrubberyCreationForm shru_form("Garden");

    std::cout << YELLOW << "\n--- Attempting to Execute Unsigned RobotomyRequestForm ---" << RESET << std::endl;
    Pedro.executeForm(rob_form);

    std::cout << YELLOW << "\n--- Attempting to Execute Unsigned ShrubberyCreationForm ---" << RESET << std::endl;
    Pedro.executeForm(shru_form);

    std::cout << YELLOW << "\n--- Attempting to Execute Unsigned PresidentialPardonForm ---" << RESET << std::endl;
    Pedro.executeForm(pres_form);

    std::cout << RED << "\n========================================" << RESET << std::endl;
    std::cout << RED << "    FAILING TESTS: EXECUTING WITHOUT SIGNATURE FINISHED" << RESET << std::endl;
    std::cout << RED << "========================================\n" << RESET << std::endl;
}

void failingGradeTests()
{
    std::cout << MAGENTA << "\n========================================" << RESET << std::endl;
    std::cout << MAGENTA << "   FAILING TESTS: EXECUTING WITH INSUFFICIENT GRADE   " << RESET << std::endl;
    std::cout << MAGENTA << "========================================\n" << RESET << std::endl;

    Bureaucrat Jeannot("Jeannot", 150);
    Bureaucrat Rico("Rico", 1);
    PresidentialPardonForm pres_form("Prisoner");
    RobotomyRequestForm rob_form("Patient_105");
    ShrubberyCreationForm shru_form("Garden");

    std::cout << CYAN << "\n--- Signing RobotomyRequestForm and Attempting Execution by Low-Ranked Bureaucrat ---" << RESET << std::endl;
    Rico.signForm(rob_form);
    Jeannot.executeForm(rob_form);

    std::cout << CYAN << "\n--- Signing ShrubberyCreationForm and Attempting Execution by Low-Ranked Bureaucrat ---" << RESET << std::endl;
    Rico.signForm(shru_form);
    Jeannot.executeForm(shru_form);

    std::cout << CYAN << "\n--- Signing PresidentialPardonForm and Attempting Execution by Low-Ranked Bureaucrat ---" << RESET << std::endl;
    Rico.signForm(pres_form);
    Jeannot.executeForm(pres_form);

    std::cout << MAGENTA << "\n========================================" << RESET << std::endl;
    std::cout << MAGENTA << "   FAILING TESTS: EXECUTING WITH INSUFFICIENT GRADE FINISHED  " << RESET << std::endl;
    std::cout << MAGENTA << "========================================\n" << RESET << std::endl;
}

int main()
{
    workingTests();
    failingSignatureTests();
    failingGradeTests();
    
    return 0;
}
