#include "Form.hpp"

Form::Form(const std::string name, const unsigned int gradeSign, const unsigned int gradeExec):_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw (GradeTooHighException());
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw (GradeTooLowException());
	std::cout << "Form default constructor called : " << *this << std::endl;
}

Form::Form(const Form& toCopy)
: _name(toCopy.getName()), _isSigned(toCopy.getSigned()), _gradeSign(toCopy.getSignGrade()), _gradeExec(toCopy.getExecGrade())
{
	std::cout << "Form copy constructor called : " << *this << std::endl;
}

//Only copy the non-const attributes can be copied after init
Form& Form::operator=(Form& a)
{
	std::cout << "Assignement operator called" << std::endl;
	if (this != &a)
		_isSigned = a.getSigned();
	return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called : "<< *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& toDisplay)
{
	os << "Form name : " << toDisplay.getName()
	<< ", Grade to sign : " << toDisplay.getSignGrade()
	<< ", Grade to exec : " << toDisplay.getExecGrade()
	<< ", Is already signed ? : " << toDisplay.getSigned();
	return (os);
}

const std::string Form::getName() const
{
	return (_name);
}

bool	Form::getSigned()	const
{
	return (_isSigned);
}

unsigned int	Form::getSignGrade()	const
{
	return (_gradeSign);
}

unsigned int	Form::getExecGrade()	const
{
	return (_gradeExec);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHigh");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLow");
}
