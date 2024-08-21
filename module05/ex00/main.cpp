# include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n-------CONSTRUCT WITH GRADE TOO HIGH----------\n" << std::endl;
    try {
        std::cout << "try to construct bureaucrat(name : Nicky Minaj, grade : 151)" << std::endl;
        Bureaucrat a("Nicky Minaj", 151);
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } 

    std::cout << "\n-------CONSTRUCT WITH GRADE TOO LOW----------\n" << std::endl;
    try {
        std::cout << "try to construct bureaucrat(name : David Guetta, grade : 0)" << std::endl;
        Bureaucrat b("David Guetta", 0);
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n-------CONSTRUCT WITH GRADE OK----------\n" << std::endl;
    try {
        Bureaucrat c("Sia", 1);//aucune exception ne sera catch
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n-------TEST OPERATORS----------\n" << std::endl;

    Bureaucrat d("Daft Punk", 150);
    Bureaucrat d2("Avicii", 112);
    d2 = d;
    std::cout << d2 << std::endl;


    std::cout << "\n-------TEST INCREMENT AND DECREMENT----------\n" << std::endl;

    std::cout << "\n-------MODIF GRADE TOO LOW----------\n" << std::endl;

    try {
        std::cout << "Before trying decrement : " << d << std::endl;
        d.decrementGrade();
    } 
    
    catch (const std::exception& e) {
        std::cerr << "Exception caught: decrement failed :" << e.what() << std::endl;
    } 
    std::cout << "After trying decrement : " << d << std::endl;

    std::cout << "\n-------MODIF GRADE TOO HIGH----------\n" << std::endl;
    
    d.validateGrade(1);
    try {
        std::cout << "Before trying increment : " << d << std::endl;
        d.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: increment failed :" << e.what() << std::endl;
    } 
    std::cout << "After trying increment : " << d << std::endl;

    std::cout << "\n-------MODIF GRADE OK----------\n" << std::endl;
    
    d.validateGrade(100);
    try {
        std::cout << "Before trying decrement : " << d << std::endl;
        d.decrementGrade();
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception caught: decrement failed : " << e.what() << std::endl;
    } 
    std::cout << "After trying decrement : " << d << std::endl;

    try {
        std::cout << "Before trying increment : " << d << std::endl;
        d.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: increment failed : " << e.what() << std::endl;
    } 
    std::cout << "After trying increment : " << d << std::endl;
     
    std::cout << "\n-------PROGRAM END----------\n" << std::endl;

    return 0;
}