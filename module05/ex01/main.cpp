# include "Bureaucrat.hpp"
# include "Form.hpp"

int main() {
    try {
        std::cout << "\n-------CONSTRUCT FORM WITH GRADE TOO LOW----------\n" << std::endl;
        Form form1("Contract", 151, 100);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n-------CONSTRUCT FORM WITH GRADE TOO HIGH----------\n" << std::endl;
        Form form2("Contract", 100, 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n-------CONSTRUCT WITH GRADE OK----------\n" << std::endl;
        Form form3("Contract", 100, 100);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n-------TEST BE SIGNED KO----------\n" << std::endl;

    try {
        Bureaucrat bureaucrat("John", 51);
        Form form("Contract", 50, 100);
        std::cout << "Before being signed: " << form.getSigned() << std::endl;
        form.beSigned(bureaucrat);
        std::cout << "After being signed: " << form.getSigned() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n-------TEST BE SIGNED OK----------\n" << std::endl;

    try {
        Bureaucrat bureaucrat("Betty", 50);
        Form form("Contract", 50, 100);
        std::cout << "Before being signed: " << form.getSigned() << std::endl;
        form.beSigned(bureaucrat);
        std::cout << "After being signed: " << form.getSigned() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n-------TEST SIGN FORM KO----------\n" << std::endl;

    try {
        Bureaucrat bureaucrat("Alice", 120);
        Form form("Contract", 100, 100);
        std::cout << "Before being signed: " << form.getSigned() << std::endl;
        bureaucrat.signForm(form);
        std::cout << "After being signed: " << form.getSigned() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n-------TEST SIGN FORM OK----------\n" << std::endl;

    try {
        Bureaucrat bureaucrat("Fredo", 100);
        Form form("Contract", 100, 100);
        std::cout << "Before being signed: " << form.getSigned() << std::endl;
        bureaucrat.signForm(form);
        std::cout << "After being signed: " << form.getSigned() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}