#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Zaphod Beeblebrox", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Default constructor called : " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& to_copy): AForm(to_copy), _target(to_copy.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called : " << *this << std::endl; 
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& a)
{
	if (this != &a)
		AForm::operator=(a);
	std::cout << "PresidentialPardonForm Assignement operator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	try{
		AForm::beExecuted(executor);
		std::cout << _target << " has been pardoned by President" << std::endl;
	}
	catch(std::exception& e){
		throw;
	}	
}

const std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& to_display)
{
	os << static_cast<const AForm&>(to_display);
	os << " Target " << to_display.getTarget();
	return (os);
}
