#include "Form.hpp"

Form::Form(const std::string name, const int gradeSign, const int gradeExec):_name(name), _isSigned(false), _gradeToSign(gradeSign), _gradeToExec(gradeExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw (GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw (GradeTooLowException());
	std::cout << "Form default constructor called : " << *this << std::endl;
}

Form::Form(const Form& toCopy)
: _name(toCopy.getName()), _isSigned(toCopy.getSigned()), _gradeToSign(toCopy.getSignGrade()), _gradeToExec(toCopy.getExecGrade())
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

int	Form::getSignGrade()	const
{
	return (_gradeToSign);
}

int	Form::getExecGrade()	const
{
	return (_gradeToExec);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
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
