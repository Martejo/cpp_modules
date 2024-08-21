#include "Bureaucrat.hpp"

//Canonical

Bureaucrat::Bureaucrat(): _name("Unamed"), _grade(150)
{
	std::cout << "Bureaucrat Default constructor called : " << *this << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade): _name(name)
{
	this->validateGrade(grade);
	std::cout << "Bureaucrat constructor called : " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy): _name(toCopy.getName())
{
	this->validateGrade(toCopy.getGrade());
	std::cout << "Bureaucrat copy constructor called : " << *this << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
	std::cout << "Bureaucrat assignement operator called" << std::endl;
	if (this != &a)
		_grade = a.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called : " << *this << std::endl;
}

//Getter
std::string const Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::validateGrade(unsigned int new_grade)
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

void Bureaucrat::signForm(AForm &form) const
{
	try{
		form.beSigned(*this);
	}
	catch(std::exception& e){
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << "." << std::endl; 
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try{
		form.execute(*this);
	}
	catch(std::exception &e){
		std::cout << _name << "couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
		return ;
	}
	std::cout << _name << " executed " << form.getName() << "." << std::endl;
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
	return "Bureaucrat::GradeTooLow";
}
