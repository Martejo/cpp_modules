#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("unamed"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
    this->validateGrade(grade);
    std::cout << "Bureaucrat Constructor called : " << *this << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy.getName())
{
    this->validateGrade(copy.getGrade());
    std::cout << "Bureaucrat Copy constructor called : " << *this << std::endl;
}

Bureaucrat&  Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat Assignement operator called" << std::endl;
    if (this != &other)
        _grade = other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called : " << *this << std::endl;
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn’t sign " << form.getName() \
        << " because " << e.what() << "." << std::endl;
    }
}



std::string const   Bureaucrat::getName() const
{
    return (_name);
}

int    Bureaucrat::getGrade() const
{
    return (_grade);
}

void    Bureaucrat::validateGrade(int new_grade)
{
    if (new_grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (new_grade > 150)
        throw Bureaucrat::GradeTooHighException();
    _grade = new_grade;
}

void    Bureaucrat::decrementGrade()
{
    validateGrade(_grade + 1);
    std::cout << "Bureaucrat Grade successfully decremented " << std::endl;
}

void    Bureaucrat::incrementGrade()
{
    validateGrade(_grade - 1);
    std::cout << "Bureaucrat Grade successfully incremented " << std::endl;
}

std::ostream&   operator<<( std::ostream &os, const Bureaucrat &to_display )
{
    os << "Bureaucrat Name : " << to_display.getName() << ", Grade : " << to_display.getGrade();
    return(os);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat::GradeTooLow";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat::GradeTooHigh";
}