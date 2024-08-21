#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const std::string target): AForm(name, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Default constructor called : " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& to_copy): AForm(to_copy), _target(to_copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called : " << *this << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& a)
{
	if (this != &a)
		AForm::operator=(a);
	std::cout << "RobotomyRequestForm Assignement operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destrctor called" << std::endl;
}

void RobotomyRequestForm::randomRobotomy() const
{
	std::srand((unsigned)time(NULL));
	int nbgen = std::rand() % 2;
	std::cout << "driiiiilll zzz zz" << std::endl;
	if (nbgen == 0)
		std::cout << _target << " have been successfully robotomized" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl; 
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	try{
		AForm::beExecuted(executor);
	}
	catch(std::exception& e){
		throw ;
	}
	this->randomRobotomy();
}

const std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& to_display)
{
	os << static_cast<const AForm&>(to_display);
	os << " Target: " << to_display.getTarget();
	return (os);
}