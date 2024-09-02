#include "Bureaucrat.hpp"
#include "Form.hpp"

// ANSI color codes for colored output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

void testFormCreation(const std::string& name, unsigned int gradeSign, unsigned int gradeExec)
{
	std::cout << BOLD << "\n--- Testing Form Creation: " << name << " ---" << RESET << std::endl;
	try {
		Form form(name, gradeSign, gradeExec);
		std::cout << GREEN << "Form created successfully: " << form << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testFormSigning(Bureaucrat& bureaucrat, Form& form)
{
	std::cout << BOLD << "\n--- Testing Form Signing by " << bureaucrat.getName() << " ---" << RESET << std::endl;
	bureaucrat.signForm(form);
	std::cout << BLUE << form << RESET << std::endl;
}

int main()
{
	std::cout << BOLD << "\n======= Bureaucrat and Form Testing =======" << RESET << std::endl;

	std::cout << BOLD << "\n--- Creating Bureaucrats ---\n" << RESET << std::endl;
	Bureaucrat highGrade("HighRank", 1);
	Bureaucrat lowGrade("LowRank", 150);
	Bureaucrat midGrade("MidRank", 75);

	std::cout << GREEN << highGrade << RESET << std::endl;
	std::cout << GREEN << lowGrade << RESET << std::endl;
	std::cout << GREEN << midGrade << RESET << std::endl;

	std::cout << BOLD << "\n--- Testing Form Creation ---" << RESET << std::endl;
	testFormCreation("TopSecret", 50, 25);
	testFormCreation("Confidential", 1, 1);
	testFormCreation("PublicNotice", 75, 50);
	testFormCreation("InvalidForm", 0, 10);  // This should throw an exception
	testFormCreation("AnotherInvalidForm", 151, 150);  // This should also throw an exception

	Form formA("PublicNotice", 75, 50);
	Form formB("Classified", 10, 5);

	std::cout << BOLD << "\n--- Testing Form Signing ---" << RESET << std::endl;
	testFormSigning(midGrade, formA);  // Should succeed
	testFormSigning(lowGrade, formA);  // Should fail due to low grade

	std::cout << BOLD << "\n--- Testing Form Signing with Insufficient Grade ---" << RESET << std::endl;
	testFormSigning(lowGrade, formB);  // Should fail due to low grade

	std::cout << BOLD << "\n--- Testing Form Signing with High Grade ---" << RESET << std::endl;
	testFormSigning(highGrade, formB);  // Should succeed

	std::cout << BOLD << "\n======= End of Tests =======" << RESET << std::endl;

	return (0);
}
